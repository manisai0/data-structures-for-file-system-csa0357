#include <iostream>
#include <string>

using namespace std;

class PhoneRecord
{
    private: 
        string persName; //key
        string telNo; // value
    
    public : 
        PhoneRecord(string persName, string telNo)
            {
            if(this->persName != persName)
                this->persName = persName;
            if(this->telNo != telNo)
                this->telNo = telNo;
            }
        void setRecord(string persName, string telNo)
            {
            if(this->persName != persName)
                this->persName = persName;
            if(this->telNo != telNo)
                this->telNo = telNo;
            }
        string getPersName()
            {
                return persName;    
            }
        string getTelNo()
            {
                return telNo;
            }
};

int main()
{
    PhoneRecord pr1("Pers 1", "tel_1");
    PhoneRecord pr2("Pers 2", "tel_2");
    PhoneRecord pr3("Pers 1", "tel_3");
    
    cout<<pr1.getPersName()<<" "<<pr1.getTelNo()<<endl;
    cout<<pr2.getPersName()<<" "<<pr2.getTelNo()<<endl;
    cout<<pr3.getPersName()<<" "<<pr3.getTelNo()<<endl;

    return 0;
}
