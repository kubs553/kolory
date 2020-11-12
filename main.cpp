#include <iostream>
#include <bitset>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    int kolor1 = 0x00aa5500;
    int kolor2 = 0x00ffffff;
    int red1 = 0x00ff0000;
    int green1 = 0x0000ff00;
    int blue1 = 0x000000ff;
    int partRed1 = (kolor1 & red1);
    int partGreen1 = (kolor1 & green1);
    int partBlue1 = (kolor1 & blue1);
    partRed1 >>= 16;
    partGreen1 >>= 8;

    int red2 = 0x00ff0000;
    int green2 = 0x0000ff00;
    int blue2 = 0x000000ff;
    int partRed2 = (kolor2 & red2);
    int partGreen2 = (kolor2 & green2);
    int partBlue2 = (kolor2 & blue2);
    partRed2 >>= 16;
    partGreen2 >>= 8;

    int stepRed = (partRed2 - partRed1) / 20;
    int stepGreen = (partGreen2 - partGreen1) / 20;
    int stepBlue = (partBlue2 - partBlue1) / 20;

    cout << "Content-Type:text/html;charset=UTF-8" << (char)13 << (char)10
          << "\n <table style='width: 300px;'>"
          << "\n <tbody>";
        for (int i = 0; i < 21; i++)
        {
            cout << "\n <tr><td bgcolor='" << hex << partRed1 << partGreen1 << setw(2) << setfill('0') << partBlue1 << "'>" << hex << partRed1 << partGreen1 << setw(2) << setfill('0') << partBlue1 << "</td></tr>";
            partRed1 += stepRed;
            partGreen1 += stepGreen;
            partBlue1 += stepBlue;

        }
        cout << "\n <tr><td bgcolor='" << partRed2 << partGreen2 << partBlue2 << "'>" << partRed2 << partGreen2 << partBlue2 << "</td></tr>";
        cout << "\n </tbody>";
        cout << "\n </table>";
    return 0;
}
