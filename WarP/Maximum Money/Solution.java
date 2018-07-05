import java.util.*;

public class Solution{

	ArrayList<ArrayList<Integer>> adjacencyList;
	ArrayList<Boolean> isVisited;
	ArrayList<Integer> money;
	int numVertices;
	int sum = 0;
	int maxSum = 0;

	public Solution(int aNumVertices, ArrayList<Integer> aMoney){
		numVertices = aNumVertices;
		//adjacencyList = new ArrayList<ArrayList<Integer>>(numVertices);
		//for(int i=0; i<adjacencyList.size(); i++)
		//	adjacencyList.set(i, new ArrayList<Integer>());
		
		adjacencyList = new ArrayList<ArrayList<Integer>>(numVertices);
		isVisited = new ArrayList<Boolean>(numVertices);
		for(int i=0; i<numVertices; i++){
			adjacencyList.add(new ArrayList<Integer>());
			isVisited.add(new Boolean(false));
		}


		money = aMoney;
	}

	public void clear(){
		for(List x : adjacencyList)
			x.clear();
		adjacencyList.clear();
	}

	public void addEdge(int u, int v){
		adjacencyList.get(u).add(v);
		adjacencyList.get(v).add(u);
	}

	public void dfsVisit(int v){
		sum+=money.get(v);
		isVisited.set(v, true);
		for(Integer w : adjacencyList.get(v)){
			if(!(isVisited.get(w))){
				dfsVisit(w);
			}
		}
	}

	public int dfsWard(){
		for(int i=0; i<numVertices; i++){
			if(!(isVisited.get(i))){
				sum = 0;
				dfsVisit(i);
				if(sum>maxSum)
					maxSum = sum;
			}
		}

		return maxSum;
	}
	
	public static void main(String[] args){
		int t, n, m;
		ArrayList<Integer> money;

		int u, v, i, temp, alpha;

		Scanner scanner = new Scanner(System.in);
		t = scanner.nextInt();
		//System.out.println(t);

		for(alpha=0; alpha<t; alpha++){
			n = scanner.nextInt();
			m = scanner.nextInt();

			money = new ArrayList<Integer>(n);
			Solution graph = new Solution(n, money);

			//System.out.println(graph.adjacencyList.size());

			for(i=0; i<n; i++){
				temp = scanner.nextInt();
				money.add(temp);
			}

			for(i=0; i<m; i++){
				u = scanner.nextInt();
				v = scanner.nextInt();

				graph.addEdge(u-1, v-1);
			}

			System.out.println(graph.dfsWard());
		}
	}

}