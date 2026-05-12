  // The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ull = unsigned long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    int caseCnt = 1;
    string line;

    while (getline(cin, line))
    {
        if (line.empty())
        {
            continue;
        } // 跳过纯粹空行（防御）
        istringstream iss(line);
        if (!(iss >> n >> d))
        {
            continue;
        } // 不是数字就跳过
        if (n == 0 && d == 0)
        {
            break;
        } // 终止条件

        int cnt = 0;
        vector<pair<double, double>> Sections;
        bool valid = true;  // 修正：vaild -> valid
        int  res   = 1;     // 每个 case 的雷达数起点必为1

          // 读取本组 n 个坐标
        while (cnt < n && getline(cin, line))
        {
            if (line.empty()){
                continue;
            } // 忽略中间空行
            istringstream iss2(line);
            int x, y;
            if (!(iss2 >> x >> y))
                continue;  // 防御
            cnt++;

            if (y > d)
            {
                valid = false;
            }

            double deltaX = sqrt(double(d) * double(d) - double(y) * double(y));
            double l      = double(x) - deltaX;
            double r      = double(x) + deltaX;
            Sections.emplace_back(l, r);
        }

          // 输出当前 case
        cout << "Case " << caseCnt << ": ";
        if (!valid || Sections.empty())
        {
            cout << -1 << endl;
        }
        else
        {
            sort(Sections.begin(), Sections.end(),
                 [&](const pair<double, double> &a, const pair<double, double> &b)
                 {
                     if (a.second != b.second)
                         return a.second < b.second;
                     return a.first < b.first;
                 });

            double last = Sections[0].second;
            for (int i = 1; i < Sections.size(); i++)
            {
                if (Sections[i].first > last)
                {
                    res++;
                    last = Sections[i].second;
                }
            }
            cout << res << endl;
        }

        caseCnt++;
    }

    return 0;
}
  // The answer is in the depth of five fathoms. And has always been her.