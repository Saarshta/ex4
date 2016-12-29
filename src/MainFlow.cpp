//
// Saar Shtalryd 307838854 & Itay Oktan 203036512
//

#include "MainFlow.h"
#include "Udp.h"


/**
 * MainFlow constructor.
 * @param sizeX the program's TaxiCenter's map X size.
 * @param sizeY the program's TaxiCenter's map Y size.
 * @param obstacles A vector of obstacles for the map.
 * @return nothing.
 */
MainFlow::MainFlow(int sizeX, int sizeY, vector<Point> obstacles) {
    map = new Map(sizeX, sizeY, obstacles);
    taxiCenter = new TaxiCenter(map);
}


void MainFlow::run(char** argv){
    int option;
    char blank;
    Udp udp(1, atoi(argv[1]));
    udp.initialize();
    char buffer[1024];
    MapRestartListener mapListener(map);
    do{
        cin >> option;
        switch (option) {
            case 1: // add a driver
            {
                int driversNum;
                cin >> driversNum;
                udp.reciveData(buffer, sizeof(buffer));
                cout << buffer << endl;
                // We received a driver, need to deserialize and create driver object.

                // we find a cab to driver
                // we set map and cab to driver
                // we add the driver to drivers list in taxicenter
                //send the cab and the map to client
                udp.sendData("The serialized cab");
                udp.sendData("The serialized map");

//                int id;
//                int age;
//                char maritalSign;
//                Status marital;
//                int exp;
//                int cabID;
//                cin >> id >> blank >> age >> blank >> maritalSign >> blank >>
//                    exp >> blank >> cabID;
//                switch (maritalSign) {
//                    // Options are Widowed, Divorced, Single, Married.
//                    case 'W':
//                        marital = Status::WIDOWED;
//                        break;
//                    case 'D':
//                        marital = Status::DIVORCED;
//                        break;
//                    case 'S':
//                        marital = Status::SINGLE;
//                        break;
//                    case 'M':
//                        marital = Status::MARRIED;
//                        break;
//                    default:
//                        throw invalid_argument("marital status is invalid");
//                }
//                Point startPos(0, 0);
//                Driver *driver = new Driver(id, age, marital, exp,
//                                            map->getNode(&startPos), &mapListener, map);
//                this->taxiCenter->addDriver(driver);
//                this->taxiCenter->assignCabToDriver(id, cabID);
//                break;
            }
            case 2: // add a trip to taxiCenter as call
            {
                int tripID;
                int startX, startY, endX, endY;
                int passNum;
                float tariff;
                cin >> tripID >> blank >> startX >> blank >> startY >> blank >> endX >> blank >> endY >> blank
                    >> passNum >> blank >> tariff;
                vector<Passenger *> passengers;
                // Serialize trip here
                Point startOfTrip(startX, startY);
                Point endOfTrip(endX, endY);
                this->taxiCenter->addCall(tripID, &startOfTrip, &endOfTrip, passengers, tariff);
                udp.sendData("The serialized cab");
                break;
            }
            case 3: // add a cab
            {
                int newCabID;
                Manufacturer manu;
                Color color;
                char colorSign, manuSign;
                int cabType;
                cin >> newCabID >> blank >> cabType >> blank >>
                    manuSign >> blank >> colorSign;
                switch (colorSign) {
                    // options are RED, BLUE, GREEN, PINK, WHITE
                    case 'W':
                        color = Color::WHITE;
                        break;
                    case 'P':
                        color = Color::PINK;
                        break;
                    case 'G':
                        color = Color::GREEN;
                        break;
                    case 'B':
                        color = Color::BLUE;
                        break;
                    case 'R':
                        color = Color::RED;
                        break;
                    default:
                        throw invalid_argument("color is invalid");
                }
                switch (manuSign) {
                    // options are  HONDA, SUBARO, TESLA, FIAT
                    case 'H':
                        manu = Manufacturer::HONDA;
                        break;
                    case 'S':
                        manu = Manufacturer::SUBARO;
                        break;
                    case 'T':
                        manu = Manufacturer::TESLA;
                        break;
                    case 'F':
                        manu = Manufacturer::FIAT;
                        break;
                    default:
                        throw invalid_argument("manufacturer is invalid");
                }
                if (cabType == 1) { //standard cab
                    Cab *cab = new StandardCab(newCabID, manu, color);
                    this->taxiCenter->addCab(cab);
                } else if (cabType == 2) { //luxury cab
                    Cab *cab = new LuxuryCab(newCabID, manu, color);
                    this->taxiCenter->addCab(cab);
                } else {
                    throw invalid_argument("cab type is invalid");
                }
                break;
            }
            case 4: // print a driver location
            {
                int driverToPrintID;
                cin >> driverToPrintID;
                Driver *driverToPrint = this->taxiCenter->getDriverByID(driverToPrintID);
                cout << *(driverToPrint->getCurrPos()) << endl;
                break;
            }
            case 6: // drive all drivers
            {
                //attach calls to drivers
                this->taxiCenter->handleOpenCalls();
                //drive all drivers to their destination
                this->taxiCenter->drive();
                break;
            }
            default: //ignoring non valid options.
                break;
        }
    }while(option!=7);
}
/**
 * Destructor.
 */
MainFlow::~MainFlow() {

    delete taxiCenter;
    delete map;
}
