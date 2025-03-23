#include <iostream>
#include <vector>
#include "transport.h"
#include "transport_factory.h"

int main(int argc, char* argv[])
{
    if (argc <= 1)
    {
        std::cerr << "Отсутствуют аргументы!\nИспользуйте: " << argv[0] << " <типы_транспорта>\n";
        return 1;
    }

    for (int i = 1; i < argc; ++i)
    {
        Transport* transport = TransportFactory::createTransport(atoi(argv[i]));
        if (transport)
        {
            transport->printParameters();
            delete transport;
            std::cout << "\n";
        }
        else
        {
            std::cout << "Неизвестный тип транспорта: " << argv[i] << "\n\n";
        }
    }

    return 0;
}
