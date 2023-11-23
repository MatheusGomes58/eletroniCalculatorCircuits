#include <iostream>
#include <cmath>

using namespace std;

// Funções para cálculos específicos

double calcularDivisorTensao(double vs, double vm, double iMax, double &r1, double &r2)
{
    if (vs <= 0 || vm <= 0 || iMax <= 0)
    {
        cerr << "Erro: Entrada inválida!" << endl;
        return -1;
    }

    r2 = vm / iMax;
    r1 = (vs - vm) / iMax;

    return 0;
}

double calcularResistorLED(double vf, double iLED, double vLED, double &rLED)
{
    if (vf <= 0 || iLED <= 0 || vLED <= 0)
    {
        cerr << "Erro: Entrada inválida!" << endl;
        return -1;
    }

    rLED = (vf - vLED) / iLED;

    return 0;
}

double calcularTransistorChave(double vs, double vcc, double ic, double &rs, double &rc)
{
    if (vs <= 0 || vcc <= 0 || ic <= 0)
    {
        cerr << "Erro: Entrada inválida!" << endl;
        return -1;
    }

    double vbe = 0.7;
    rs = (vs - vbe) / ic;
    rc = vcc / ic;

    return 0;
}

double calcularPolarizacaoBasica(double vs, double vcc, double vce, double beta, double ic, double &rs, double &rc)
{
    if (vs <= 0 || vcc <= 0 || vce <= 0 || beta <= 0 || ic <= 0)
    {
        cerr << "Erro: Entrada inválida!" << endl;
        return -1;
    }

    double vbe = 0.7;
    rs = (vs - vbe) / ic;
    rc = (vcc - vce) / ic;

    return 0;
}

double calcularDivisorTensaoBaseTransistor(double vcc, double vce, double vre, double ic, double beta, double &r1, double &r2, double &rc, double &re)
{
    if (vcc <= 0 || vce <= 0 || vre <= 0 || ic <= 0 || beta <= 0)
    {
        cerr << "Erro: Entrada inválida!" << endl;
        return -1;
    }

    double vbe = 0.7;
    r2 = (vce - vbe) / ic;
    r1 = vre / (beta * ic);
    rc = vce / ic;
    re = vre / ic;

    return 0;
}

double calcularAmplificadorInversor(double vi, double vo, double r1, double &rf)
{
    if (vi <= 0 || vo <= 0 || r1 <= 0)
    {
        cerr << "Erro: Entrada inválida!" << endl;
        return -1;
    }

    rf = (vo / vi - 1) * r1;

    return 0;
}

double calcularAmplificadorNaoInversor(double vi, double vo, double r1, double &rf)
{
    if (vi <= 0 || vo <= 0 || r1 <= 0)
    {
        cerr << "Erro: Entrada inválida!" << endl;
        return -1;
    }

    rf = (vo / vi) * r1;

    return 0;
}

// Função principal
int main()
{
    int escolha;

    do
    {
        // Exibir o menu
        cout << "\nMenu Inicial:" << endl;
        cout << "1. Circuito divisor de Divisor de tensão" << endl;
        cout << "2. Resistor de LED" << endl;
        cout << "3. Transistor como Chave" << endl;
        cout << "4. Polarização básica do transistor" << endl;
        cout << "5. Polarização por divisor de tensão na base do transistor" << endl;
        cout << "6. Montagem Amplificador Inversor com amp-op" << endl;
        cout << "7. Montagem Amplificador não inversor com amp-op" << endl;
        cout << "8. Sair do programa" << endl;
        cout << "Escolha uma opção: ";
        cin >> escolha;

        // Variáveis comuns
        double vs, vm, iMax;
        double vf, iLED, vLED;
        double vcc, vsTransistor, icTransistor;
        double vccPolarizacao, vcePolarizacao, icPolarizacao, betaPolarizacao;
        double vccDivisor, vceDivisor, vreDivisor, icDivisor, betaDivisor;
        double viAmp, voAmp, r1Amp, r2Amp, rcAmp, reAmp;

        switch (escolha)
        {
        case 1: // Circuito divisor de Divisor de tensão
            cout << "Informe a tensão de entrada (Vs): ";
            cin >> vs;
            cout << "Informe a tensão de saída (Vm): ";
            cin >> vm;
            cout << "Informe a corrente máxima no circuito: ";
            cin >> iMax;

            double r1Divisor, r2Divisor;
            if (calcularDivisorTensao(vs, vm, iMax, r1Divisor, r2Divisor) == 0)
            {
                cout << "Valor do R1: " << r1Divisor << endl;
                cout << "Valor do R2: " << r2Divisor << endl;
            }
            break;

        case 2: // Resistor de LED
            cout << "Informe a tensão de alimentação (VF): ";
            cin >> vf;
            cout << "Informe a corrente no LED: ";
            cin >> iLED;
            cout << "Informe a tensão no LED: ";
            cin >> vLED;

            double rLED;
            if (calcularResistorLED(vf, iLED, vLED, rLED) == 0)
            {
                cout << "Valor do RLED: " << rLED << endl;
            }
            break;

        case 3: // Transistor como Chave
            cout << "Informe a tensão de fonte (VS): ";
            cin >> vsTransistor;
            cout << "Informe a tensão de coletor (VCC): ";
            cin >> vcc;
            cout << "Informe a corrente de coletor (IC): ";
            cin >> icTransistor;

            double rsTransistor, rcTransistor;
            if (calcularTransistorChave(vsTransistor, vcc, icTransistor, rsTransistor, rcTransistor) == 0)
            {
                cout << "Valor do RS: " << rsTransistor << endl

                    ;
                cout << "Valor do RC: " << rcTransistor << endl;
            }
            break;

        case 4: // Polarização básica do transistor
            cout << "Informe a tensão de fonte (VS): ";
            cin >> vs;
            cout << "Informe a tensão de coletor (VCC): ";
            cin >> vccPolarizacao;
            cout << "Informe a tensão de coletor-emissor (VCE): ";
            cin >> vcePolarizacao;
            cout << "Informe o Beta do transistor: ";
            cin >> betaPolarizacao;
            cout << "Informe a corrente de operação (IC): ";
            cin >> icPolarizacao;

            double rsPolarizacao, rcPolarizacao;
            if (calcularPolarizacaoBasica(vs, vccPolarizacao, vcePolarizacao, betaPolarizacao, icPolarizacao, rsPolarizacao, rcPolarizacao) == 0)
            {
                cout << "Valor do RS: " << rsPolarizacao << endl;
                cout << "Valor do RC: " << rcPolarizacao << endl;
            }
            break;

        case 5: // Polarização por divisor de tensão na base do transistor
            cout << "Informe a tensão de coletor (VCC): ";
            cin >> vccDivisor;
            cout << "Informe a tensão de coletor-emissor (VCE): ";
            cin >> vceDivisor;
            cout << "Informe a tensão de emissor (VRE): ";
            cin >> vreDivisor;
            cout << "Informe o Beta do transistor: ";
            cin >> betaDivisor;
            cout << "Informe a corrente de operação (IC): ";
            cin >> icDivisor;

            double r1DivisorBase, r2DivisorBase, rcDivisorBase, reDivisorBase;
            if (calcularDivisorTensaoBaseTransistor(vccDivisor, vceDivisor, vreDivisor, icDivisor, betaDivisor, r1DivisorBase, r2DivisorBase, rcDivisorBase, reDivisorBase) == 0)
            {
                cout << "Valor do R1: " << r1DivisorBase << endl;
                cout << "Valor do R2: " << r2DivisorBase << endl;
                cout << "Valor do RC: " << rcDivisorBase << endl;
                cout << "Valor do RE: " << reDivisorBase << endl;
            }
            break;

        case 6: // Montagem Amplificador Inversor com amp-op
            cout << "Informe o valor de Vi: ";
            cin >> viAmp;
            cout << "Informe o valor de Vo: ";
            cin >> voAmp;
            cout << "Informe o valor de R1: ";
            cin >> r1Amp;

            double rfAmpInversor;
            if (calcularAmplificadorInversor(viAmp, voAmp, r1Amp, rfAmpInversor) == 0)
            {
                cout << "Valor do RF: " << rfAmpInversor << endl;
            }
            break;

        case 7: // Montagem Amplificador não inversor com amp-op
            cout << "Informe o valor de Vi: ";
            cin >> viAmp;
            cout << "Informe o valor de Vo: ";
            cin >> voAmp;
            cout << "Informe o valor de R1: ";
            cin >> r1Amp;

            double rfAmpNaoInversor;
            if (calcularAmplificadorNaoInversor(viAmp, voAmp, r1Amp, rfAmpNaoInversor) == 0)
            {
                cout << "Valor do RF: " << rfAmpNaoInversor << endl;
            }
            break;

        case 8: // Sair do programa
            cout << "Programa encerrado." << endl;
            break;

        default:
            cout << "Opção inválida. Tente novamente." << endl;
        }

        cout << "\nPressione qualquer tecla para continuar...";
        cin.ignore();
        cin.get();

    } while (escolha != 8);

    return 0;
}