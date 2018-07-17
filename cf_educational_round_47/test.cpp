#include <bits/stdc++.h>
#define ff first
#define ss second
#define endl "\n"  // Since endl forces a buffer flush which slows down large I/O operations.
#define pb push_back
#define input(c) for (size_t i = 0; i < sizeof(c)/sizeof(c[0]); i++) cin>>c[i];
#define exit_message(s) return 0*printf(s)
#define show(c) for (auto i: c) cout<<i<<" "; cout<<"\n";
#define FOR0(n) for (int i = 0; i < n; i++)
#define FOR(a, n) for (int i = a; i < n; i++)

using namespace std;
typedef long long ll;
typedef pair<int, int> pr;
ifstream in("input.txt");
ofstream out("output.txt");
const int mod = 1e9 + 7, size = 1e5;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin>>s;
  // 222000111
  int n = s.length(), pos2 = n;
  int c[3] = {};
  for (int i = n - 1; i >= 0; i--)
  {
    c[s[i] - '0']++;
    if (s[i] == '2')
    {
      // n - i numbers occured so far.
      // c0 0's after this 2.
      int j;
      for (j = i; j < i + c[1]; j++)
      {
        s[j] = '1';
      }
      int temp = j;
      s[j++] = '2';
//      cout<<"b";
      for (; j < pos2; j++)
        s[j] = '0';
      c[0] = 0;
//      cout<<"after alter\n"<<s<<"\npos2 = "<<pos2<<"\n\n";
      pos2 = temp;
    }
  }
  memset(c, 0, 3*sizeof(int));
  for (int i = 0; i < pos2; i++)
  {
    c[s[i] - '0']++;
  }
  for (int i = 0; i < c[0]; i++)
  {
    s[i] = '0';
  }
  for (int i = c[0]; i < pos2; i++)
  {
    s[i] = '1';
  }
  
  cout<<s<<"\n";

  return 0;
}