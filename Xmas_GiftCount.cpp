#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> vec_int;
typedef std::map<int, vec_int> map_vec_house;

class House
{
private:
    int houseNum;
    map_vec_house routeMap;
    vec_int directlyConnectedHouses;
    bool singlyConnected;
    int giftsCount;

public:
    enum HouseConnection
    {
        SELF = 100001,
        DIRECT
    };
    House(int house_num)
    {
        houseNum = house_num;
        singlyConnected = false;
        giftsCount = 0;
    }
    void addToRouteMap(const int& connector_house, const int& connected_house=House::SELF)
    {
        vec_int v;
        map_vec_house::iterator itr = routeMap.find(connector_house);

        if ( itr != routeMap.end() )
        {
            v = itr->second;
            v.push_back(connected_house);
            itr->second = v;
        }
        else
        {
            v.push_back(connected_house);
            routeMap[connector_house] = v;
            directlyConnectedHouses.push_back(connector_house);
        }
        singlyConnected = (routeMap.size() == 1);
    }

    int getGiftsCount() const { return giftsCount; }

    int storeGift_findNextHouse(int house_num)
    {
        giftsCount++;
        int nextHouse = -1;

        //if house_num is directly connected
        if ( isAlreadyMapped(house_num) )
        {
            nextHouse = DIRECT;
        }
        else
        {
            map_vec_house::iterator itr=routeMap.begin();
            //if house_num is the only connected house to this house and house_num leads to all other houses
            if ( singlyConnected )
            {
                nextHouse = itr->first;
            }
            else
            {
                //iterate over directly connected houses to locate required house
                for(itr = routeMap.begin(); itr != routeMap.end(); itr++)
                {
                    vec_int v = itr->second;
                    for(short unsigned int j=0;j<v.size();j++)
                    {
                        if ( v[j] == house_num )
                        {
                            nextHouse = itr->first;
                            break;
                        }
                    }
                }
            }
        }
        return nextHouse;
    }

    bool isSinglyConnected() { return singlyConnected; }

    vec_int& getMapKeys()
    {
        return directlyConnectedHouses;
    }

    bool isAlreadyMapped(int connector_house)
    {
        map_vec_house::iterator itr = routeMap.find(connector_house);
        return (itr != routeMap.end());
    }

    int getHouseNum() const
    {
        return houseNum;
    }
};

void createHousesConnectionMap(const vec_int &v, House* cur_house, House *h[]);
void createHousesConnectionMap(vec_int v, House* cur_house, House* h_arr[], int h_no, int prevHouse=-1);
void findNextHouses(int start_h, int end_h, House* h_arr[]);
void setHousesConnection(int houseCount, House* h_arr[]);
void processSantaTrip(int daysofTrip, int houseCount, House* house[]);

int main ( )
{
    int houseCount = 0;
    int daysofTrip = 0;
    cin >> houseCount;
    cin >> daysofTrip;
    if ( houseCount <= 0 || houseCount > 100000 )
    {
        cout << "Count of houses should be between 1-100000." << endl;
        exit(1);
    }
    if ( daysofTrip <= 0 || daysofTrip > 100000 )
    {
        cout << "Trip of days should be between 1-100000." << endl;
        exit(1);
    }

    House* house[houseCount];
    for (int i=0;i<houseCount; i++)
    {
        house[i] = NULL;
    }

    //function for receiving routes between houses
    setHousesConnection(houseCount, house);

    for (int i=0;i<houseCount;i++)
    {
        if ( !house[i]->isSinglyConnected() )
        {
            //function for recursively creating connection between connected houses
            createHousesConnectionMap(house[i]->getMapKeys(), house[i], house);
        }
    }

    //function for receiving trip houses and storing gifts in lying-in-route houses
    processSantaTrip(daysofTrip, houseCount, house);

    //finding house with maximum no of gifts
    int max_Gifts = 0; int house_num = 0;
    for(int i=0;i<houseCount;i++)
    {
        int gifts = house[i]->getGiftsCount();
        if (gifts >= max_Gifts)
        {
            max_Gifts = gifts;
            house_num = house[i]->getHouseNum();
        }
    }
    cout << "Max Gifts are " << max_Gifts << ", stored in house " << house_num << endl;
    return 0;
}

void setHousesConnection(int houseCount, House *house[])
{
    int readerVar;
    int housenum1, houseIdx1, housenum2, houseIdx2;

    for (int i=0;i<houseCount-1; i++)
    {
        cin >> readerVar;

        if ( readerVar <= 0 || readerVar > houseCount )
        {
            cout << "Invalid house number." << endl;
            exit(1);
        }
        housenum1 = readerVar; houseIdx1 = housenum1-1;

        if (!house[houseIdx1])
        {
            house[houseIdx1] = new House(housenum1);
        }

        cin >> readerVar;

        if ( readerVar <= 0 || readerVar > houseCount || readerVar == housenum1 )
        {
            cout << "Invalid house number." << endl;
            exit(1);
        }
        housenum2 = readerVar; houseIdx2 = housenum2-1;

        if (!house[houseIdx2])
        {
            house[houseIdx2] = new House(housenum2);
        }

        if ( house[houseIdx1]->isAlreadyMapped(housenum2) || house[houseIdx2]->isAlreadyMapped(housenum1) )
        {
            cout << "Houses already mapped." << endl;
            exit(1);
        }
        else
        {
            house[houseIdx2]->addToRouteMap(housenum1);
            house[houseIdx1]->addToRouteMap(housenum2);
        }
    }
}

void processSantaTrip(int daysofTrip, int houseCount, House* house[])
{
    int readerVar;
    for (int i=0;i<daysofTrip; i++)
    {
        cin >> readerVar;
        if ( readerVar <= 0 || readerVar > houseCount )
        {
            cout << "Invalid house number." << endl;
            exit(1);
        }
        int startHouse = readerVar;

        cin >> readerVar;
        if ( readerVar <= 0 || readerVar > houseCount )
        {
            cout << "Invalid house number." << endl;
            exit(1);
        }
        int endHouse = readerVar;

        if ( startHouse == endHouse )
        {
            house[startHouse-1]->storeGift_findNextHouse(endHouse);
        }
        else
        {
            findNextHouses(startHouse, endHouse, house);
        }
    }
}

void findNextHouses(int start_h, int end_h, House* h_arr[])
{
    int loopHouse = start_h;
    //looping until Santa gets just one short of the destination house
    while ( loopHouse != House::DIRECT )
    {
        loopHouse = h_arr[loopHouse-1]->storeGift_findNextHouse(end_h);
    }
    h_arr[end_h-1]->storeGift_findNextHouse(end_h);
}

void createHousesConnectionMap(const vec_int &v, House* cur_house, House* h_arr[])
{
    //loop for iterating over directly connected houses only
    for(short unsigned i=0;i<v.size();i++)
    {
        //skip if loop house is only connected to cur_house as it does not lead to any other house; else execute below if
        if ( !h_arr[v[i]-1]->isSinglyConnected())
        {
            //get list of directly connected houses to the loop house and iterate over each house
            vec_int newV = h_arr[v[i]-1]->getMapKeys();
            vec_int newV2;
            for(short unsigned int j=0;j<newV.size();j++)
            {
                if ( cur_house->getHouseNum() != newV[j] )
                {
                    if ( !h_arr[newV[j]-1]->isSinglyConnected() )
                        newV2.push_back(newV[j]);
                    cur_house->addToRouteMap ( v[i], newV[j] );
                }
            }
            //if any of the sub-houses leads to other houses, iterate over it
            if ( !newV2.empty())
                createHousesConnectionMap(newV2, cur_house, h_arr, v[i]);
        }
    }
}

void createHousesConnectionMap(vec_int v, House* cur_house, House* h_arr[], int h_no, int prevHouse)
{
    //loop for iterating over sub-houses connected to cur_house and directly connected to h_no
    for(short unsigned i=0;i<v.size();i++)
    {
        if ( !(cur_house->getHouseNum() == v[i] || h_arr[v[i]-1]->isSinglyConnected()) )
        {
            vec_int newV = h_arr[v[i]-1]->getMapKeys();
            vec_int newV2;
            for(short unsigned int j=0;j<newV.size();j++)
            {
                if ( !(cur_house->getHouseNum() == newV[j] || newV[j] == h_no || newV[j] == prevHouse) )
                {
                    if ( !h_arr[newV[j]-1]->isSinglyConnected() )
                        newV2.push_back(newV[j]);
                    cur_house->addToRouteMap ( h_no, newV[j] );
                }
            }
            //recursively finding connection to other connected houses
            if ( !newV2.empty())
                createHousesConnectionMap(newV2, cur_house, h_arr, h_no, v[i]);
        }
    }
}
