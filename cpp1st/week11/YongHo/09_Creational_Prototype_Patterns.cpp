//A prototype pattern is used in software development when the type of objects to create is determined by a prototypical instance,
// which is cloned to produce new objects. this pattern is used, for example, when the inherent const of creating 
// a new object in the standard way (e.g. using the new keyword) is prohibitively expensive for a given application.

#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

//Record is the base prototype
class Record
{
    public:
        virtual ~Record() {};
        virtual void print() = 0;
        virtual std::unique_ptr<Record> clone() = 0;
};

//CarRecord is a concrete prototype
class CarRecord : public Record
{
    private:
        std::string car_Name;
        int car_Id;
    public:
        CarRecord(std::string carName, int Id) : car_Name(carName), car_Id(Id)
        {            
        }

        void print() override
        {
            std::cout << "Car Record" << std::endl
                        << "Name : " << car_Name << std::endl
                        << "Number : " << car_Id << std::endl;
        }

        std::unique_ptr<Record> clone() override
        {
            return std::make_unique<CarRecord>(*this);
        }
};

//BikeRecord is the Concrete Prototype
class BikeRecord : public Record
{
    private:
        std::string bike_name;
        int bike_id;
    public:
        BikeRecord(std::string bikeName, int bikeId) : bike_name(bikeName), bike_id(bikeId)
        {            
        }

        void print() override
        {
            std::cout << "Bike Record" << std::endl
                        << "Name : " << bike_name << std::endl
                        << "Number : " << bike_id << std::endl;
        }

        std::unique_ptr<Record> clone() override
        {
            return std::make_unique<BikeRecord>(*this);
        }
};

//PersonRecord is the Concrete Prototype
class PersonRecord : public Record
{
    private:
        std::string person_Name;
        int person_Age;
    public:
        PersonRecord(std::string personName, int personAge) : person_Name(personName), person_Age(personAge)
        {            
        }

        void print() override
        {
            std::cout << "Person Record" << std::endl
                        << "Name : " << person_Name << std::endl
                        << "Number : " << person_Age << std::endl;
        }

        std::unique_ptr<Record> clone() override
        {
            return std::make_unique<PersonRecord>(*this);
        }
};

//Opaque record type, avolids exposing concrete implementations
enum RecordType
{
    CAR,
    BIKE,
    PERSON
};

//RecordFactory is the client
class RecordFactory
{
    private:
        std::unordered_map<RecordType, std::unique_ptr<Record>, std::hash<int>> records;

    public:
        RecordFactory()
        {
            records[CAR] = std::make_unique<CarRecord>("Ferrari", 5050);
            records[BIKE] = std::make_unique<BikeRecord>("Yamaha", 2525);
            records[PERSON] = std::make_unique<PersonRecord>("Tom", 25);
        }

        std::unique_ptr<Record> createRecord(RecordType recordType)
        {
            return records[recordType]->clone();
        }
};

int main()
{
    RecordFactory recordFactory;

    auto record = recordFactory.createRecord(CAR);
    record->print();

    record = recordFactory.createRecord(BIKE);
    record->print();

    record = recordFactory.createRecord(PERSON);
    record->print();
}