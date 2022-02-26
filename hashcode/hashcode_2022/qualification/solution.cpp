#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>

// Structs.
struct Project {
	int id;
	std::string name;
	int days, score, best_before;
	std::vector<std::pair<std::string, int>> roles;  // pair of skill, level.
};

std::ostream& operator<<(std::ostream& os, const Project& p) {
	return os << p.id << " "  << p.name << " " << p.days << " " << p.score << " " << p.best_before << std::endl;
}

struct Contributor {
	int id;
	std::string name;
	std::vector<std::pair<std::string, int>> skills;  // pair of skill_name, level.
};

std::ostream& operator<<(std::ostream& os, const Contributor& p) {
	return os << p.id << " "  << p.name << std::endl;
}

struct Schedule {
	std::vector<std::pair<std::string, std::vector<std::string>>> schedule;
};

void PrintSchedule(const Schedule& schedule) {
	std::cout << schedule.schedule.size() << std::endl;
	for (const auto& pair : schedule.schedule) {
		std::cout << pair.first << std::endl;
		for (const std::string& contributor_name : pair.second) {
			std::cout << contributor_name << " ";
		}
		std::cout << std::endl;
	}
}

int GetExistingSkillLevelOfContrib(int contributor_id, const std::set<std::pair<int, int>>& skill_id_pairs) {
	for (auto it = skill_id_pairs.begin(); it != skill_id_pairs.end(); it++) {
		if (it->second == contributor_id) return it->first;
	}
	return 0;
}

bool SomeoneCanMentor(const std::map<int, int>& current_assignment_contrib_to_role, const std::set<std::pair<int, int>>& skill_id_pairs, int required_skill_level) {
	for (auto it = current_assignment_contrib_to_role.begin(); it != current_assignment_contrib_to_role.end(); it++) {
		if (GetExistingSkillLevelOfContrib(it->first, skill_id_pairs) >= required_skill_level) return true;
	}
	return false;
}

Schedule Solve(const std::vector<Project>& projects, const std::vector<Contributor>& contributors) {
	// Preprocess skill level order for fast traversal later.
	std::unordered_map<std::string, std::set<std::pair<int, int>>> skill_to_level_and_id;  // {level, id} pairs.
	for (const Contributor& contributor : contributors) {
		for (const auto& skill : contributor.skills) {
			if (skill_to_level_and_id.find(skill.first) == skill_to_level_and_id.end())
				skill_to_level_and_id[skill.first] = std::set<std::pair<int, int>>();
			skill_to_level_and_id[skill.first].insert({skill.second, contributor.id});
		}
	}

	// Create sorted order of projects based on some metric.
	std::vector<std::pair<float, int>> order;  // pair of metric, project_id.
	for (const Project& p : projects) {
		// order.push_back({p.best_before, p.id});
		order.push_back({-p.score, p.id});
	}
	std::sort(order.begin(), order.end());

	// Sorted order of project objects.
	std::vector<Project> sorted_projects;
	for (const auto& pair : order) {
		sorted_projects.push_back(projects[pair.second]);
	}

	Schedule answer;
	answer.schedule = std::vector<std::pair<std::string, std::vector<std::string>>>();

	// Map to keep track of availability.
	std::unordered_map<int, long long int> contributor_available_at;
	for (int i = 0; i < contributors.size(); i++) {
		contributor_available_at[i] = 0;
	}


	for (const Project& project : sorted_projects) {
		std::map<int, int> assigned_contrib_to_role;  // Stores new contributors we assign to roles for *this* project.
		bool not_using_this_project = false;

		for (int role_id = 0; role_id < project.roles.size(); role_id++) {
			const auto& role = project.roles[role_id];
			
			// Need to find an eligible person.

			if (role.second > 0 && skill_to_level_and_id.find(role.first) == skill_to_level_and_id.end()) {
				// No person with this skill available.
				not_using_this_project = true;
				break;
			}

			// For Attempt #3: Adding mentoring complexity to optimize solution.
			int least_level_required = role.second;
			if (SomeoneCanMentor(assigned_contrib_to_role, skill_to_level_and_id[role.first], role.second)) {
				least_level_required = role.second - 1;
			}
			
			auto it = role.second > 0 ? skill_to_level_and_id[role.first].lower_bound({least_level_required, -1}) : skill_to_level_and_id[role.first].begin();
			if (it == skill_to_level_and_id[role.first].end()) {
				// Didn't find anyone with sufficient level of skill.
				not_using_this_project = true;
				break;
			}

			// Skip to first eligible in the list as some may already be assigned to this project.
			while (assigned_contrib_to_role.find(it->second) != assigned_contrib_to_role.end()) {
				it++;
				if (it == skill_to_level_and_id[role.first].end()) break;
			}

			// Iterate and find eligible one with earliest availability.
			int eligible_contributor_available_earliest = (it != skill_to_level_and_id[role.first].end()) ? it->second : -1;
			while (it != skill_to_level_and_id[role.first].end()) {
				if (assigned_contrib_to_role.find(it->second) == assigned_contrib_to_role.end()) {
					// Not already assigned this contributor to this project, so can consider.
					if ((eligible_contributor_available_earliest == -1) || (contributor_available_at[it->second] < contributor_available_at[eligible_contributor_available_earliest])) {
						// Found a better contributor.
						eligible_contributor_available_earliest = it->second;
					}
				}
				it++;
			}


			if (eligible_contributor_available_earliest == -1) {
				// Didn't find anyone.
				not_using_this_project = true;
				break;
			}

			// Found someone for this role.
			assigned_contrib_to_role[eligible_contributor_available_earliest] = role_id;
		}

		if (!not_using_this_project && assigned_contrib_to_role.size() >= project.roles.size()) {
			// Will schedule this project.
			std::pair<std::string, std::vector<std::string>> entry;
			entry.first = project.name;
			entry.second = std::vector<std::string>(project.roles.size(), "");
			for (auto it = assigned_contrib_to_role.begin(); it != assigned_contrib_to_role.end(); it++) {
				contributor_available_at[it->first] += project.days;
				entry.second[it->second] = contributors[it->first].name;
			}
			answer.schedule.push_back(entry);

			// Attempt #2 optimization: Increase level of each assigned contributor if it's equal to role requirement.
			for (auto it = assigned_contrib_to_role.begin(); it != assigned_contrib_to_role.end(); it++) {
				const std::string& skill = project.roles[it->second].first;
				int existing_skill_level_of_contrib = GetExistingSkillLevelOfContrib(it->first, skill_to_level_and_id[skill]);
				// Attempt #4: increase skill level by 1 if was below required level.
				if (existing_skill_level_of_contrib <= project.roles[it->second].second) {
					skill_to_level_and_id[skill].erase({existing_skill_level_of_contrib, it->first});
					skill_to_level_and_id[skill].insert({existing_skill_level_of_contrib + 1, it->first});
				}
			}
		}
	}

	return answer;
}

int main() {

	// Read input.
	int C, P;
	std::cin >> C >> P;

	std::vector<Project> projects(P);
	std::vector<Contributor> contributors(C);

	// Read contributors.
	for (int i = 0; i < C; i++) {
		contributors[i].id = i;
		std::cin >> contributors[i].name;
		
		int S;
		std::cin >> S;

		while (S--) {
			std::string skill;
			int level;
			std::cin >> skill >> level;
			contributors[i].skills.push_back({skill, level});
		}
	};

	// Read projects.
	for (int i = 0; i < P; i++) {
		projects[i].id = i;
		std::cin >> projects[i].name >> projects[i].days >> projects[i].score >> projects[i].best_before;

		int R;
		std::cin >> R;
		while (R--) {
			std::string skill;
			int level;
			std::cin >> skill >> level;
			projects[i].roles.push_back({skill, level});
		}
	}

	// Print input.
	// std::cout << "Projects: " << std::endl;
	// for (const auto& project : projects) {
	// 	std::cout << project << std::endl;
	// }

	// std::cout << "Contributors: " << std::endl;
	// for (const auto& contrib : contributors) {
	// 	std::cout << contrib << std::endl;
	// }

	// Solve.
	Schedule answer = Solve(projects, contributors);

	// Print solution.
	PrintSchedule(answer);

	return 0;
}