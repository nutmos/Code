//Copyright 2013 @Nutmos' Programming
//All Right Reserved
//Compile with Xcode 4.6
#include <iostream>

using namespace std;

typedef struct _general {
    unsigned int soldier;
    int chaloeyOf;
}general;

int chaloeyOfWho(int number, general gen[]) {
    return (gen[number].chaloeyOf == -1)?number:chaloeyOfWho(gen[number].chaloeyOf, gen);
}
int whoWinThisWar(int number1, int number2, general gen[]) {
    if (gen[number1].soldier > gen[number2].soldier) {
        return number1;
    }
    else if (gen[number1].soldier < gen[number2].soldier) {
        return number2;
    }
    else {
        if (number1 < number2) {
            return number1;
        }
        else if (number1 > number2) {
            return number2;
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    general gen[n];
    for (register int i = 0; i < n; i++) {
        cin >> gen[i].soldier;
        gen[i].chaloeyOf = -1;
    }
    unsigned int war[m][2];
    int resultWar[m];
    for (register int i = 0; i < m; i++) {
        cin >> war[i][0] >> war[i][1];
        war[i][0]--;
        war[i][1]--;
    }
    for (register int i = 0; i < m; i++) {
        if (gen[war[i][0]].soldier == 0 && gen[war[i][1]].soldier == 0) {
            war[i][0] = chaloeyOfWho(war[i][0], gen);
            war[i][1] = chaloeyOfWho(war[i][1], gen);
            //cout << "first if" << endl;
            //cout << "0 = " << war[i][0] << " 1 = " << war[i][1] << endl;
            //cout << "number of soldier 0 = " << gen[war[i][0]].soldier << endl;
            //cout << "number of soldier 1 = " << gen[war[i][1]].soldier << endl;
            if (war[i][0] == war[i][1]) {
                resultWar[i] = -2;
            }
            else {
                resultWar[i] = whoWinThisWar(war[i][0], war[i][1], gen);
                if (war[i][0] == resultWar[i]) {
                    gen[resultWar[i]].soldier += gen[war[i][1]].soldier >> 1;
                    gen[war[i][1]].soldier = 0;
                    gen[war[i][1]].chaloeyOf = war[i][0];
                }
                else {
                    gen[resultWar[i]].soldier += gen[war[i][0]].soldier >> 1;
                    gen[war[i][0]].soldier = 0;
                    gen[war[i][0]].chaloeyOf = war[i][1];
                }
            }
        }
        else if (gen[war[i][0]].soldier == 0 && gen[war[i][1]].soldier != 0) {
            war[i][0] = chaloeyOfWho(war[i][0], gen);
            //cout << "second if" << endl;
            //cout << "0 = " << war[i][0] << " 1 = " << war[i][1] << endl;
            //cout << "number of soldier 0 = " << gen[war[i][0]].soldier << endl;
            //cout << "number of soldier 1 = " << gen[war[i][1]].soldier << endl;
            if (war[i][0] == war[i][1]) {
                resultWar[i] = -2;
            }
            else {
                resultWar[i] = whoWinThisWar(war[i][0], war[i][1], gen);
                if (war[i][0] == resultWar[i]) {
                    gen[resultWar[i]].soldier += gen[war[i][1]].soldier >> 1;
                    gen[war[i][1]].soldier = 0;
                    gen[war[i][1]].chaloeyOf = war[i][0];
                }
                else {
                    gen[resultWar[i]].soldier += gen[war[i][0]].soldier >> 1;
                    gen[war[i][0]].soldier = 0;
                    gen[war[i][0]].chaloeyOf = war[i][1];
                }
            }
        }
        else if (gen[war[i][0]].soldier != 0 && gen[war[i][1]].soldier == 0) {
            war[i][1] = chaloeyOfWho(war[i][1], gen);
            //cout << "third if" << endl;
            //cout << "0 = " << war[i][0] << " 1 = " << war[i][1] << endl;
            //cout << "number of soldier 0 = " << gen[war[i][0]].soldier << endl;
            //cout << "number of soldier 1 = " << gen[war[i][1]].soldier << endl;
            if (war[i][0] == war[i][1]) {
                resultWar[i] = -2;
            }
            else {
                resultWar[i] = whoWinThisWar(war[i][0], war[i][1], gen);
                if (war[i][0] == resultWar[i]) {
                    gen[resultWar[i]].soldier += gen[war[i][1]].soldier >> 1;
                    gen[war[i][1]].soldier = 0;
                    gen[war[i][1]].chaloeyOf = war[i][0];
                }
                else {
                    gen[resultWar[i]].soldier += gen[war[i][0]].soldier >> 1;
                    gen[war[i][0]].soldier = 0;
                    gen[war[i][0]].chaloeyOf = war[i][1];
                }
            }
        }
        else {
            //cout << "forth if" << endl;
            //cout << "0 = " << war[i][0] << " 1 = " << war[i][1] << endl;
            //cout << "number of soldier 0 = " << gen[war[i][0]].soldier << endl;
            //cout << "number of soldier 1 = " << gen[war[i][1]].soldier << endl;
            if (war[i][0] == war[i][1]) {
                resultWar[i] = -2;
            }
            else {
                resultWar[i] = whoWinThisWar(war[i][0], war[i][1], gen);
                if (war[i][0] == resultWar[i]) {
                    //cout << "if" << endl;
                    gen[resultWar[i]].soldier += gen[war[i][1]].soldier >> 1;
                    gen[war[i][1]].soldier = 0;
                    gen[war[i][1]].chaloeyOf = war[i][0];
                }
                else {
                    //cout << "else" << endl;
                    gen[resultWar[i]].soldier += gen[war[i][0]].soldier >> 1;
                    gen[war[i][0]].soldier = 0;
                    gen[war[i][0]].chaloeyOf = war[i][1];
                    //cout << war[i][0] << " soldier = " << gen[war[i][0]].soldier << endl;
                    //cout << war[i][0] << " chaloeyOf = " << gen[war[i][0]].chaloeyOf << endl;
                }
            }
            //cout << endl;
        }
    }
    for (register int i = 0; i < m; i++) {
        cout << ++resultWar[i] << endl;
    }
}