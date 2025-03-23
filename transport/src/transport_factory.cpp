#include "transport_factory.h"
#include "transport.h"

Transport* TransportFactory::createTransport(int type)
{
    switch (type)
    {
        case 0: return new Motorcycle();
        case 1: return new Scooter();
        case 2: return new Car();
        case 3: return new Bus();
        default: return nullptr;
    }
}
