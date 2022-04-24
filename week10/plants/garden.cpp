#include "garden.h"

Garden::Garden(int n)
{
    if (n < 0) throw NUM_ERROR;
    _parcels.resize(n);
    //for(int i = 0; i<n; ++i) _parcels[i] = new Parcel(i);
    for(int i = 0; i < n; ++i) _parcels[i] = new Parcel();
}

Parcel* Garden::getParcel(int i) const
{
    if(i >= 0 && i < (int)_parcels.size()) return _parcels[i];
    else return nullptr;
}

void Garden::plant(int id, Plant* plant, int date){
    if (id < 1 || id > _parcels.size())
    {
        throw PARCEL_ERROR;
    }
    getParcel(id-1)->plant(plant, date);
}


std::vector<int> Garden::canHarvest(int date)
{
    std::vector<int> result;
    /*for(Parcel* p : _parcels){
        if( nullptr!=p->getPlant()
            &&  date - p->getplantingDate() == p->getPlant()->getRipeningTime() )
                result.push_back(p->getId());
    }*/
    for (int i=0; i<_parcels.size(); ++i)
    {
        Parcel* p=_parcels[i];
        if( nullptr != p->getPlant() && p->getPlant()->isVegetable()
            &&  date - p->getplantingDate() == p->getPlant()->getRipeningTime() )
                result.push_back(i+1);
    }
    return result;
}
