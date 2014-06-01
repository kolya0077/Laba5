#include <iostream>
#include <locale.h>
using namespace std;
int w[500][500]; /// @param w - matrix of the paths
bool used[500]; /// @param used - contains used points
int d[500]; /// @param d - contain the lengths of the paths
int inf = 1000000000; /// @param w - infinity for calculations
int main()
{
	setlocale(LC_ALL, "rus");
    int n, m, v1, v2, x=0, y=0, z=0;
    cout << "������� ���������� ������: ";
    cin >> n;
    cout << "������� ���������� ���: ";
    cin >> m; 
    cout << "�� ����� ������� ����� ������: ";
    cin >> v1;
    cout << "�� ����� ������� ���� ������ ����������: ";
    cin >> v2;
    v1--;
	v2--;
    memset(w, 0, sizeof(w));
    memset(d, 1000000000, sizeof(d));
    memset(used, false, sizeof(used));
    for (int i=0;i<n;i++)
	{
        d[i]=inf;
	}
    for (int i=0;i<m;i++)
    {
        cout << "���� " << i+1 << endl;
        cout << "\t�� ����� ������� ����? ";
        cin >> x;
        cout << "\t� ����� ������� ����� ������ ����? ";
        cin >> y;
        cout << "\t����� ��� ����? ";
        cin >> z;
        w[x-1][y-1]=z;
        w[y-1][x-1]=z;
    }
    d[v1]=0;
    while (true)
    {
        int from,zfrom=inf;
        for (int i=0;i<n;i++)
        {
            if ((zfrom>d[i]) && !(used[i]))
            {
                from=i;
                zfrom=d[i];
            }
        }
        if (zfrom>=inf)
		{
            break;
		}
        used[from]= true;
        for(int to=0;to<n;to++)
		{
            if (w[from][to]!=0)
			{
                if ((!used[to]) && (d[to]>d[from]+w[from][to]))
				{
                    d[to]=d[from]+w[from][to];
				}
			}
		}
    }
    
    if (d[v2]<inf)
	{
        cout << "����������� ����������: " << d[v2] << endl; ///@return the closest path
	}
    else
	{
        cout << "-1";
	}
    return 0;
}