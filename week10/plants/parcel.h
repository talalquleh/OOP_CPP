#pragma once
#include "plant.h"

class Parcel
{
    private:
        //int _id;
        Plant* _plant;
        int _plantingDate;
    public:
        enum Error {PLANTING_ERROR};
        //Parcel(int id): _id(id), _plant(nullptr), _plantingDate(0) {}
        Parcel(): _plant(nullptr), _plantingDate(1) {}
        void plant(Plant* plant, int date) { if (date < 1 || date > 12) { throw PLANTING_ERROR; } _plant = plant; _plantingDate = date; }
        //int getId() const { return _id; }

        /// getters
        Plant* getPlant() const { return _plant; }
        int getplantingDate() const { return _plantingDate; }
};
