
#include <iostream>
#include <fstream>
#include <string>

enum State {first, second, op};
enum Ops {undefinedOp, plus, minus, mult, divide, mod, lt, gt, lte, gte, andop, orop, bsl, bsr, pp, mm, notop};

Ops getOp(std::string s) {
    if (s.compare("+") == 0) {
        return plus;
    } else if (s.compare("-") == 0) {
        return minus;
    } else if (s.compare("*") == 0) {
        return mult;
    } else if (s.compare("/") == 0) {
        return divide;
    } else if (s.compare("%") == 0) {
        return mod;
    } else if (s.compare("<") == 0) {
        return lt;
    } else if (s.compare(">") == 0) {
        return gt;
    } else if (s.compare("<=") == 0) {
        return lte;
    } else if (s.compare(">=") == 0) {
        return gte;
    } else if (s.compare("&&") == 0) {
        return andop;
    } else if (s.compare("||") == 0) {
        return orop;
    } else if (s.compare("<<") == 0) {
        return bsl;
    } else if (s.compare(">>") == 0) {
        return bsr;
    } else if (s.compare("++") == 0) {
        return pp;
    } else if (s.compare("--") == 0) {
        return mm;
    } else if (s.compare("~") == 0) {
        return notop;
    } else {
        return undefinedOp;
    }
}

int main() {
    std::string line;
    std::fstream myfile ("input.txt");
    std::ofstream tempFile ("temp.txt");

    while ( getline (myfile,line) )
    {
        int a = 0;
        int b = 0;
        int c = 0;

        State parseState = first;
        for(char* cp = &line[0]; *cp != '\0'; ++cp) {
            char ch = *cp;
            if (ch == ',') {
                parseState = (State)(parseState + 1);
            } else {
                switch (parseState) {
                case first:
                    a = a * 10;
                    a += ch - '0';
                    break;
                case second:
                    if (ch > '9' || ch < '0') {
                        parseState = op;
                    } else {
                        b = b * 10;
                        b += ch - '0';
                        break;
                    }
                case op:
                    switch (getOp(std::string(cp))){
                        case plus:
                            c = a + b;
                            break;
                        case minus:
                            c = a - b;
                            break;
                        case mult:
                            c = a * b;
                            break;
                        case divide:
                            c = a / b;
                            break;
                        case mod:
                            c = a % b;
                            break;
                        case lt:
                            c = (a < b);
                            break;
                        case gt:
                            c = (a > b);
                            break;
                        case lte:
                            cp++;
                            c = (a <= b);
                            break;
                        case gte:
                            cp++;
                            c = (a >= b);
                            break;
                        case andop:
                            cp++;
                            c = (a && b);
                            break;
                        case orop:
                            cp++;
                            c = (a || b);
                            break;
                        case bsl:
                            cp++;
                            c = (a << b);
                            break;
                        case bsr:
                            cp++;
                            c = (a >> b);
                            break;
                        case pp:
                            cp++;
                            c = a + 1;
                            break;
                        case mm:
                            cp++;
                            c = a - 1;
                            break;
                        case notop:
                            c = ~a;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
                }
            }
        }

        tempFile << line << ',' << c << '\n';
    }
    myfile.close();
    tempFile.close();

    remove("input.txt");

    std::ofstream f1 ("input.txt");
    std::fstream f2 ("temp.txt");

    while ( getline (f2,line) )
    {
        f1 << line << '\n';
    }

    remove("temp.txt");

    return 0;
}   