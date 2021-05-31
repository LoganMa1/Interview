#include "smart_ptr.h"
#include <iostream>
#include <string>

struct MediaAsset
{

    virtual ~MediaAsset() = default;
};

struct Song : public MediaAsset
{
    std::string artist;
    std::string title;
    Song(const std::string& artist_, const std::string& title_) :
        artist{ artist_ }, title{ title_ } {}
};

struct Photo : public MediaAsset
{
    std::string date;
    std::string location;
    std::string subject;
    Photo(
        const std::string& date_,
        const std::string& location_,
        const std::string& subject_) :
        date{ date_ }, location{ location_ }, subject{ subject_ } {}
};

int main()
{
//example1
    MyShare_ptr<Song> sp2(new Song("Li","Birds"));
    MyShare_ptr<Song> sp5(nullptr);
    int _sp2 = sp2.GetCount();
    int _sp5 = sp5.GetCount();
    std::cout<<"_sp2="<<_sp2<<" "<<"_sp5="<<_sp5<<"\n";

    sp5 = sp2;
    _sp2 = sp2.GetCount();
    _sp5 = sp5.GetCount();
    std::cout<<"_sp2="<<_sp2<<" "<<"_sp5="<<_sp5<<"\n";

    MyShare_ptr<Song> sp6(sp2);
    int _sp6 = sp6.GetCount();
    _sp2 = sp2.GetCount();
    _sp5 = sp5.GetCount();
    std::cout<<"_sp2="<<_sp2<<" "<<"_sp5="<<_sp5<<" "<<"_sp6="<<_sp6<<"\n";
    
}








