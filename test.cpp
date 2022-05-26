#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int T;
    cin >> T;
    double pi = 3.141592653589793238;
    for (int i = 0; i < T; i++)
    {
        int R, A, B;
        cin >> R >> A >> B;
        double Area = pi * R * R;
        while (R > 0)
        {
            R = R * A;
            Area += pi * R * R;
            R = R / B;
            Area += pi * R * R;
        }
        cout << "Case #" << i + 1 << ": " << fixed << setprecision(6) << Area << endl;
    }
    return 0;
}