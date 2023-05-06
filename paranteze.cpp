#include <iostream>
#include <stack>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("paranteze.in");
ofstream g("paranteze.out");

int main()
{
    int n;

    f>>n;
    f.get();

    vector<int>v(n+1,0);
    stack <int> s;
    string sir;
    getline(f,sir);

    for(int i=0; i<n; i++)
    {
        switch (sir[i]) {
            case '{':
                s.push(i);
                break;
            case '[':
                s.push(i);
                break;
            case '(':
                s.push(i);
                break;
            case '}':
                if (!s.empty() && sir[s.top()] == '{') {
                    v[i] = 1;
                    v[s.top()] = 1;
                    s.pop();
                }
                else {
                    s.push(i);
                }
                break;
            case ']':
                if (!s.empty() && sir[s.top()] == '[') {
                    v[i] = 1;
                    v[s.top()] = 1;
                    s.pop();
                }
                else {
                    s.push(i);
                }
                break;
            case ')':
                if (!s.empty() && sir[s.top()] == '(') {
                    v[i] = 1;
                    v[s.top()] = 1;
                    s.pop();
                }
                else {
                    s.push(i);
                }
                break;
            default:
                break;
        }
    }

    int lc = 0, lmax = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            lc++;
            if(lc > lmax)
                lmax = lc;
        } else {
            lc = 0;
        }
    }

    g << lmax << endl;

    return 0;
}
