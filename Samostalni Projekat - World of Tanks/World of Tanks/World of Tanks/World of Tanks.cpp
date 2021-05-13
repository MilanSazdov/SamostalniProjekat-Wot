// World of Tanks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <list>
#include <iterator>

#define MAX_SIZE_FOR_NAME 40
#pragma warning(disable : 4996)

enum class GrenadeType{AP,HE, HEAT, APCR, HESH};
enum class FirstAidKitType { SmallFirstAidKit, LargeFirstAidKit };
enum class RepairKitType { SmallRepairKit, LargeRepairKit };
enum class FireExtinguisherType { ManualFireExtinguisher, AutomaticFireExtinguisher };
enum class OtherConsumables { Coffe, Chocolate, Tea };
enum class Nation{GERMANY, USSR, USA, FRANCE, UK, CHINA, JAPAN, CZECHOSLOVAKIA, POLAND, SWEDEN, ITALY};
enum Tier{I, II, III, IV, V, VI, VII, VIII, IX, X};
enum class TypeOfBattle{RandomBattle, RankedBattle, SteelHunter, Stronghold, SpecialBattle, TeamTraining};
enum class PlatoonVoiceChat{EnabledVoice, NotEnabledVoice};
enum class PlatoonChat{Enabled, NotEnabled};


class CrewMember{

protected:

    char name[MAX_SIZE_FOR_NAME];
    char lastname[MAX_SIZE_FOR_NAME];
    double experience;
    double heigth;
    double weight;
    int age;
    bool repairs;
    bool concealment; // kamuflaza
    bool firefighting;
    bool brothers_in_arms;

public :

    CrewMember() {
        strcpy_s(name, "Serzhant");
        strcpy_s(lastname, "Kulik");
        experience = 2536.78;
        heigth = 1.72;
        weight = 63.456;
        age = 31;
        repairs = false;
        concealment = false;
        firefighting = true;
        brothers_in_arms = true;
    }

    CrewMember(char* Name, char* LastName, float exp, float h, float w, int age, bool repairs, bool con, bool firefighting, bool bia) {
        strcpy_s(name, Name);
        strcpy_s(lastname, LastName);
        experience = exp;
        heigth = h;
        weight = w;
        this->age = age;
        this->repairs = repairs;
        concealment = con;
        this->firefighting = firefighting;
        brothers_in_arms = bia;
    }
    
    CrewMember(CrewMember &cm) {
        strcpy_s(name, cm.name);
        strcpy_s(lastname, cm.lastname);
        experience = cm.experience;
        heigth = cm.heigth;
        weight = cm.weight;
        age = cm.age;
        repairs = cm.repairs;
        concealment = cm.concealment;
        firefighting = cm.firefighting;
        brothers_in_arms = cm.brothers_in_arms;
    }

    void setName(char* n){
        strcpy_s(name, n);
    }

    void setLastName(char* ln) {
        strcpy_s(lastname, ln);
    }

    void setExperience(double exp) {
        experience = exp;
    }
    
    void setHeigth(double h) {
        heigth = h;
    }

    void setWeight(double w) {
        weight = w;
    }

    void setAge(int a) {
        age = a;
    }

    void setRepairs(bool rep) {
        repairs = rep;
    }

    void setConcealment(bool con) {
        concealment = con;
    }

    void setFirefighting(bool fire) {
        firefighting = fire;
    }

    void setBrothersInArms(bool bia) {
        brothers_in_arms = bia;
    }

    char* getName(){    
        return name;
    }

    char* getLastName(){
        return lastname;
    }

    double getExperience() const{

        return experience;
    }

    double getHeigth() const{
        return heigth;
    }

    double getWeight() const{
        return weight;
    }

    int getAge() const{
        return age;
    }

    bool getRepairs() const{
        return repairs;
    }

    bool getConcealment() const{
        return concealment;
    }

    bool getFirefighting() const{
        return firefighting;
    }

    bool getBrothersInArms() const{
        return brothers_in_arms;
    }

    friend std::ostream& operator<<(std::ostream& os, const CrewMember& cm) {
        
        os << "Name : " << cm.name << std::endl;
        os << "Last name : " << cm.lastname << std::endl;
        os << "Experience : " << cm.experience << std::endl;
        os << "Height : " << cm.heigth << std::endl;
        os << "Weight : " << cm.weight << std::endl;
        os << "Age : " << cm.age << std::endl;
        os << "Repairs : ";
        if (cm.repairs == true) {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        os << "Concealment : ";
        if (cm.concealment == true) {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        os << "Firefighting : ";
        if (cm.firefighting == true) {
            os << "YES" << std::endl;
        }
        else
        {
            os << "No" << std::endl;
        }

        os << "Brothers in arms : ";
        if (cm.brothers_in_arms == true) {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }
        return os;
    }
};


class Commander : public CrewMember {

private:

    bool mentor;
    bool recon;
    bool jack_of_all_trades;
    bool eagle_eye;
    bool sixth_sense;

public:
    
    Commander() : CrewMember(){
        
        mentor = true;
        recon = false;
        jack_of_all_trades = false;
        eagle_eye = true;
        sixth_sense = true;
    }

    Commander(bool m, bool r, bool jofat, bool ee, bool ss, char* Name, char* LastName, float exp, float h, float w, int age, bool repairs, bool con, bool firefighting, bool bia) : CrewMember(Name, LastName, exp, h, w, age, repairs, con, firefighting, bia){

        mentor = m;
        recon = r;
        jack_of_all_trades = jofat;
        eagle_eye = ee;
        sixth_sense = ss;
    }

    Commander(Commander& com) : CrewMember(com){

        mentor = com.mentor;
        recon = com.recon;
        jack_of_all_trades = com.jack_of_all_trades;
        eagle_eye = com.eagle_eye;
        sixth_sense = com.sixth_sense;
    }

    void setMentor(bool men){
        mentor = men;
    }

    void setRecon(bool rec){
        recon = rec;
    }

    void setJackOfAllTrades(bool joat) {
        jack_of_all_trades = joat;
    }

    void setEagleEye(bool eagle) {
        eagle_eye = eagle;
    }

    void setSixthSense(bool ss) {
        sixth_sense = ss;
    }

    bool getMentor() const {
        return mentor;
    }

    bool getRecon() const {
        return recon;
    }

    bool getJackOfAllTrades()const {
        return jack_of_all_trades;
    }

    bool getEagleEye()const {
        return eagle_eye;
    }

    bool getSixthSense()const{
        return sixth_sense;
    }

    friend std::ostream& operator<<(std::ostream& os, const Commander& c) {

        os << "COMMANDER : " << std::endl;
        os << (const CrewMember&)c;
        os << "Mentor : ";
        if (c.mentor == true) {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        os << "Recon : ";
        if (c.recon == true) {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        os << "Jack of all trades : ";
        if (c.jack_of_all_trades == true) {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        os << "Eagle eye : ";
        if (c.eagle_eye == true)
        {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO " << std::endl;
        }

        os << "Sixth sense : ";
        if (c.sixth_sense == true)
        {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        return os;
    }
};

class Driver : public CrewMember {

private:

    bool controlled_impact;
    bool off_road_driving;
    bool smooth_ride;
    bool preventative_maintenance;
    bool clutch_braking;

public:

    Driver() : CrewMember() {
        
        controlled_impact = true;
        off_road_driving = true;
        smooth_ride = false;
        preventative_maintenance = false;
        clutch_braking = false;
    }

    Driver(bool ci, bool ord, bool sr, bool PreMein, bool cb, char* Name, char* LastName, float exp, float h, float w, int age, bool repairs, bool con, bool firefighting, bool bia) : CrewMember(Name, LastName, exp, h, w, age, repairs, con, firefighting, bia){
        
        controlled_impact = ci;
        off_road_driving = ord;
        smooth_ride = sr;
        preventative_maintenance = PreMein;
        clutch_braking = cb;
    }

    Driver(Driver& dr) : CrewMember(dr) {

        controlled_impact = dr.controlled_impact;
        off_road_driving = dr.off_road_driving;
        smooth_ride = dr.smooth_ride;
        preventative_maintenance = dr.preventative_maintenance;
        clutch_braking = dr.clutch_braking;
    }

    void setControlledImpact(bool ConImpact) {
        controlled_impact = ConImpact;
    }

    void setOffRoadDriving(bool ord) {
        off_road_driving = ord;
    }

    void setSmoothRide(bool SmoothRide) {
        smooth_ride = SmoothRide;
    }

    void setPreventativeMaintenance(bool PreMain) {
        preventative_maintenance = PreMain;
    }

    void setClutchBraking(bool cb){
        clutch_braking = cb;
    }

    bool getControlledImpact() const {
        return controlled_impact;
    }

    bool getOffRoadDriving() const {
        return off_road_driving;
    }

    bool getSmoothRide() const {
        return smooth_ride;
    }

    bool getPreventativeMaintenance() const {
        return preventative_maintenance;
    }

    bool getClutchBraking() const {
        return clutch_braking;
    }

    friend std::ostream& operator<<(std::ostream& os, const Driver& d) {

        os << "DRIVER : " << std::endl;
        os << (const CrewMember&)d;
        os << "Controlled impact : ";
        if (d.controlled_impact == true)
        {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        os << "Off road driving : ";
        if (d.off_road_driving == true) {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        os << "Smooth ride : ";
        if (d.smooth_ride == true)
        {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        os << "Preventative maintenance : ";
        if (d.preventative_maintenance == true)
        {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        os << "Clutch braking : ";
        if (d.clutch_braking == true)
        {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        return os;
    }
};

class Gunner : public CrewMember {

private:

    bool designated_target;
    bool armorer;
    bool deadeye;
    bool snap_shot;

public:

    Gunner() : CrewMember() {

        designated_target = true;
        armorer = true;
        deadeye = false;
        snap_shot = false;
    }

    Gunner(bool dt, bool arm, bool deye, bool ss, char* Name, char* LastName, float exp, float h, float w, int age, bool repairs, bool con, bool firefighting, bool bia) : CrewMember(Name, LastName, exp, h, w, age, repairs, con, firefighting, bia) {
        
        designated_target = dt;
        armorer = arm;
        deadeye = deye;
        snap_shot = ss;
    }

    Gunner(Gunner& gun): CrewMember(gun){

        designated_target = gun.designated_target;
        armorer = gun.armorer;
        deadeye = gun.deadeye;
        snap_shot = gun.snap_shot;
    }

    void setDesignatedTarget(bool dt) {
        designated_target = dt;
    }

    void setArmorer(bool arm) {
        armorer = arm;
    }

    void setDeadeye(bool deye) {
        deadeye = deye;
    }

    void setSnapShot(bool ss) {
        snap_shot = ss;
    }

    bool getDesignatedTarget() const {
        return designated_target;
    }

    bool getArmorer() const {
        return armorer;
    }

    bool getDeadeye() const {
        return deadeye;
    }

    bool getSnapShot() const {
        return snap_shot;
    }

    friend std::ostream& operator<<(std::ostream& os, const Gunner& g) {
        os << "GUNNER : " << std::endl;
        os << (const CrewMember&)g;
        os << "Designated target : ";
        if (g.designated_target == true) {
            os<< "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        os << "Armorer : ";
        if (g.armorer == true) {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        os << "Deadeye: ";
        if (g.deadeye == true)
        {
            os<<"YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        os << "Snapshot : ";
        if (g.snap_shot == true)
        {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        return os;
    }

};

class Loader : public CrewMember {

private:

    bool intuition;
    bool adrenaline_rush;
    bool safe_stowage;

public:

    Loader() : CrewMember() {
        intuition = true;
        adrenaline_rush = true;
        safe_stowage = false;
    }

    Loader(bool intu, bool ar, bool SafeStowage, char* Name, char* LastName, float exp, float h, float w, int age, bool repairs, bool con, bool firefighting, bool bia) : CrewMember(Name, LastName, exp, h, w, age, repairs, con, firefighting, bia) {
       
        intuition = intu;
        adrenaline_rush = ar;
        safe_stowage = SafeStowage;
    }

    Loader(Loader& l) : CrewMember(l) {

        intuition = l.intuition;
        adrenaline_rush = l.adrenaline_rush;
        safe_stowage = l.safe_stowage;
    }

    void setIntuition(bool intu) {
        intuition = intu;
    }

    void setAdrenalineRush(bool ar) {
        adrenaline_rush = ar;
    }

    void setSafeStowage(bool SafeS) {
        safe_stowage = SafeS;
    }

    bool getIntuition() const {
        return intuition;
    }

    bool getAdrenalineRush() const {
        return adrenaline_rush;
    }

    bool getSafeStowage() const {
        return safe_stowage;
    }

    friend std::ostream& operator<<(std::ostream& os, const Loader& l) {
        os << "LOADER : " << std::endl;
        os << (const CrewMember&)l;
        os << "Intuition : ";
        if (l.intuition == true) {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        os << "Adrenaline rush : ";
        if (l.adrenaline_rush == true)
        {
            os << "YES" << std::endl;
        }

        else
        {
            os << "NO" << std::endl;
        }

        os << "Safe stowage : ";
        if (l.safe_stowage == true) {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        return os;
    }
};



class RadioOperator : public CrewMember {

private:

    bool situational_awareness;
    bool call_of_vengeance;
    bool signal_boosting;
    bool relaying;

public:

    RadioOperator() : CrewMember() {

        situational_awareness = true;
        call_of_vengeance = false;
        signal_boosting = false;
        relaying = true;
    }

    RadioOperator(bool sa, bool cov, bool sb, bool rel, char* Name, char* LastName, float exp, float h, float w, int age, bool repairs, bool con, bool firefighting, bool bia) : CrewMember(Name, LastName, exp, h, w, age, repairs, con, firefighting, bia) {
        
        situational_awareness = sa;
        call_of_vengeance = cov;
        signal_boosting = sb;
        relaying = rel;
    }

    RadioOperator(RadioOperator& ro) : CrewMember(ro) {

        situational_awareness = ro.situational_awareness;
        call_of_vengeance = ro.call_of_vengeance;
        signal_boosting = ro.signal_boosting;
        relaying = ro.relaying;
    }

    void setSituationalAwareness(bool sa) {
        situational_awareness = sa;
    }

    void setCallOfVengeance(bool cov) {
        call_of_vengeance = cov;
    }

    void setSignalBoosting(bool sb) {
        signal_boosting = sb;
    }

    void setRelaying(bool rel) {
        relaying = rel;
    }

    bool getSituationalAwareness() const {
        return situational_awareness;
    }

    bool getCallOfVengeance() const {
        return call_of_vengeance;
    }

    bool getSignalBoosting() const {
        return signal_boosting;
    }

    bool getRelaying() const {
        return relaying;
    }

    friend std::ostream& operator<<(std::ostream& os, const RadioOperator& ro) {
        os<<"RADIO OPERATOR : " << std::endl;
        
        os << (const CrewMember&)ro;

        os << "Situational awareness : ";
        if (ro.situational_awareness == true)
        {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        os << "Call of vengeance : ";
        if (ro.call_of_vengeance == true) {
            os << "YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        os << "Signal boosting : ";
        if (ro.signal_boosting == true) {
            os<<"YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }

        os << "Relaying : ";
        if (ro.relaying == true) {
            os<<"YES" << std::endl;
        }
        else
        {
            os << "NO" << std::endl;
        }
        
        return os;
    }
};

class Crew {

protected:

    Commander com;
    Driver d;
    Gunner g;
    Loader l;
    RadioOperator ro;

public:

    Crew() {

        com = Commander(); 
        d = Driver();
        g = Gunner();
        l = Loader();
        ro = RadioOperator();
    }

    Crew(bool m, bool r, bool jofat, bool ee, bool ss, char* Name, char* LastName, float exp, float h, float w, int age, bool repairs, bool con, bool firefighting, bool bia, bool ci, bool ord, bool sr, bool PreMein, bool cb, char* NameDriver, char* LastNameDriver, float expDriver, float hDriver, float wDriver, int ageDriver, bool repairsDriver, bool conDriver, bool firefightingDriver, bool biaDriver, bool dt, bool arm, bool deye, bool ssGuner, char* NameGuner, char* LastNameGuner, float expGuner, float hGuner, float wGuner, int ageGuner, bool repairsGuner, bool conGuner, bool firefightingGuner, bool biaGuner, bool intuLoader, bool arLoader, bool SafeStowageLoader, char* NameLoader, char* LastNameLoader, float expLoader, float hLoader, float wLoader, int ageLoader, bool repairsLoader, bool conLoader, bool firefightingLoader, bool biaLoader, bool saRadioOperator, bool covRadioOperator, bool sbRadioOperator, bool relRadioOperator, char* NameRadioOperator, char* LastNameRadioOperator, float expRadioOperator, float hRadioOperator, float wRadioOperator, int ageRadioOperator, bool repairsRadioOperator, bool conRadioOperator, bool firefightingRadioOperator, bool biaRadioOperator){
        
        com = Commander (m, r, jofat, ee, ss, Name, LastName, exp, h, w, age, repairs, con, firefighting, bia);
        d = Driver(ci, ord, sr, PreMein, cb, NameDriver, LastNameDriver, expDriver, hDriver, wDriver, ageDriver, repairsDriver, conDriver, firefightingDriver, biaDriver);
        g = Gunner(dt, arm, deye, ssGuner, NameGuner, LastNameGuner, expGuner, hGuner, wGuner, ageGuner, repairsGuner, conGuner, firefightingGuner, biaGuner);
        l = Loader(intuLoader, arLoader, SafeStowageLoader, NameLoader, LastNameLoader, expLoader, hLoader, wLoader, ageLoader, repairsLoader, conLoader, firefightingLoader, biaLoader);
        ro = RadioOperator(saRadioOperator, covRadioOperator, sbRadioOperator, relRadioOperator, NameRadioOperator, LastNameRadioOperator, expRadioOperator, hRadioOperator, wRadioOperator, ageRadioOperator, repairsRadioOperator, conRadioOperator, firefightingRadioOperator, biaRadioOperator);
    }

    Crew(Crew& c) {

        com = Commander(c.com);
        d = Driver(c.d);
        g = Gunner(c.g);
        l = Loader(c.l);
        ro = RadioOperator(c.ro);
    }

    // Seteri za Crew
    /*
    void setCommander(bool m, bool r, bool jofat, bool ee, bool ss, char* Name, char* LastName, float exp, float h, float w, int age, bool repairs, bool con, bool firefighting, bool bia) {
        
        com.setMentor(m);
        com.setRecon(r);
        com.setJackOfAllTrades(jofat);
        com.setEagleEye(ee);
        com.setSixthSense(ss);
        com.setName(Name);
        com.setLastName(LastName);
        com.setExperience(exp);
        com.setHeigth(h);
        com.setWeight(w);
        com.setAge(age);
        com.setRepairs(repairs);
        com.setConcealment(con);
        com.setFirefighting(firefighting);
        com.setBrothersInArms(bia);
    }*/

    //SETERI ZA COMMANDER - A

    void setCommanderMentor(bool mentor) {
        com.setMentor(mentor);
    }

    void setCommanderRecon(bool recon) {
        com.setRecon(recon);
    }

    void setCommanderJackOfAllTrades(bool jack_of_all_trades) {
        com.setJackOfAllTrades(jack_of_all_trades);
    }

    void setCommanderEagleEye(bool eagle_eye) {
        com.setEagleEye(eagle_eye);
    }

    void setCommanderSixthSense(bool sixth_sense) {
        com.setSixthSense(sixth_sense);
    }

    void setCommanderName(char* name){
        com.setName(name);
    }

    void setCommanderLastName(char* last_name) {
        com.setLastName(last_name);
    }

    void setCommanderExperience(double experience) {
        com.setExperience(experience);
    }

    void setCommanderHeigth(double heigth) {
        com.setHeigth(heigth);
    }

    void setCommanderWeight(double weight) {
        com.setWeight(weight);
    }

    void setCommanderAge(int age) {
        com.setAge(age);
    }

    void setCommanderRepairs(bool repairs) {
        com.setRepairs(repairs);
    }

    void setCommanderConcealment(bool concealment) {
        com.setConcealment(concealment);
    }

    void setCommanderFirefighting(bool firefighting) {
        com.setFirefighting(firefighting);
    }

    void setCommanderBrothersInArms(bool brothers_in_arms) {
        com.setBrothersInArms(brothers_in_arms);
    }

    /*
    void setDriver(bool ci, bool ord, bool sr, bool PreMein, bool cb, char* NameDriver, char* LastNameDriver, float expDriver, float hDriver, float wDriver, int ageDriver, bool repairsDriver, bool conDriver, bool firefightingDriver, bool biaDriver) {

        d.setControlledImpact(ci);
        d.setOffRoadDriving(ord);
        d.setSmoothRide(sr);
        d.setPreventativeMaintenance(PreMein);
        d.setClutchBraking(cb);
        d.setName(NameDriver);
        d.setLastName(LastNameDriver);
        d.setExperience(expDriver);
        d.setHeigth(hDriver);
        d.setWeight(wDriver);
        d.setAge(ageDriver);
        d.setRepairs(repairsDriver);
        d.setConcealment(conDriver);
        d.setFirefighting(firefightingDriver);
        d.setBrothersInArms(biaDriver);
    }*/

    //Seteri za Driver - a

    void setDriverControlledImpact(bool controlled_impact) {
        d.setControlledImpact(controlled_impact);
    }

    void setDriverOffRoadDriving(bool off_road_driving) {
        d.setOffRoadDriving(off_road_driving);
    }

    void setDriverSmoothRide(bool smooth_ride) {
        d.setSmoothRide(smooth_ride);
    }

    void setDriverPreventativeMaintenance(bool preventative_maintenance) {
        d.setPreventativeMaintenance(preventative_maintenance);
    }

    void setDriverClutchBraking(bool clutch_breaking) {
        d.setClutchBraking(clutch_breaking);
    }

    void setDriverName(char* name) {
        d.setName(name);
    }

    void setDriverLastName(char* last_name) {
        d.setLastName(last_name);
    }

    void setDriverExperience(double experience) {
        d.setExperience(experience);
    }

    void setDriverHeigth(double heigth) {
        d.setHeigth(heigth);
    }

    void setDriverWeight(double weight) {
        d.setWeight(weight);
    }

    void setDriverAge(int age) {
        d.setAge(age);
    }

    void setDriverRepairs(bool repairs) {
        d.setRepairs(repairs);
    }

    void setDriverConcealment(bool concealment) {
        d.setConcealment(concealment);
    }

    void setDriverFirefighting(bool firefighting) {
        d.setFirefighting(firefighting);
    }

    void setDriverBrothersInArms(bool brothers_in_arms) {
        d.setBrothersInArms(brothers_in_arms);
    }

    /*
    void setGunner(bool dt, bool arm, bool deye, bool ssGuner, char* NameGuner, char* LastNameGuner, float expGuner, float hGuner, float wGuner, int ageGuner, bool repairsGuner, bool conGuner, bool firefightingGuner, bool biaGuner) {
        
        g.setDesignatedTarget(dt);
        g.setArmorer(arm);
        g.setDeadeye(deye);
        g.setSnapShot(ssGuner);
        g.setName(NameGuner);
        g.setLastName(LastNameGuner);
        g.setExperience(expGuner);
        g.setHeigth(hGuner);
        g.setWeight(wGuner);
        g.setAge(ageGuner);
        g.setRepairs(repairsGuner);
        g.setConcealment(conGuner);
        g.setFirefighting(firefightingGuner);
        g.setBrothersInArms(biaGuner);
    }*/


    //Seteri za Gunner - a

    void setGunnerDesignatedTarget(bool designated_target) {
        g.setDesignatedTarget(designated_target);
    }

    void setGunnerArmorer(bool armorer) {
        g.setArmorer(armorer);
    }

    void setGunnerDeadeye(bool deadeye) {
        g.setDeadeye(deadeye);
    }

    void setGunnerSnapShot(bool snap_shot) {
        g.setSnapShot(snap_shot);
    }

    void setGunnerName(char* name) {
        g.setName(name);
    }

    void setGunnerLastName(char* last_name) {
        g.setLastName(last_name);
    }

    void setGunnerExperience(double experience) {
        g.setExperience(experience);
    }

    void setGunnerHeigth(double heigth) {
        g.setHeigth(heigth);
    }

    void setGunnerWeight(double weight) {
        g.setWeight(weight);
    }

    void setGunnerAge(int age) {
        g.setAge(age);
    }

    void setGunnerRepairs(bool repairs) {
        g.setRepairs(repairs);
    }

    void setGunnerConcealment(bool concealment) {
        g.setConcealment(concealment);
    }

    void setGunnerFirefighting(bool firefighting) {
        g.setFirefighting(firefighting);
    }

    void setGunnerBrothersInArms(bool brothers_in_arms) {
        g.setBrothersInArms(brothers_in_arms);
    }

    /*
    void setLoader(bool intuLoader, bool arLoader, bool SafeStowageLoader, char* NameLoader, char* LastNameLoader, float expLoader, float hLoader, float wLoader, int ageLoader, bool repairsLoader, bool conLoader, bool firefightingLoader, bool biaLoader) {

        l.setIntuition(intuLoader);
        l.setAdrenalineRush(arLoader);
        l.setSafeStowage(SafeStowageLoader);
        l.setName(NameLoader);
        l.setLastName(LastNameLoader);
        l.setExperience(expLoader);
        l.setHeigth(hLoader);
        l.setWeight(wLoader);
        l.setAge(ageLoader);
        l.setRepairs(repairsLoader);
        l.setConcealment(conLoader);
        l.setFirefighting(firefightingLoader);
        l.setBrothersInArms(biaLoader);
    }*/

    //Seteri za Loader - a

    void setLoaderIntuition(bool intuition) {
        l.setIntuition(intuition);
    }

    void setLoaderAdrenalineRush(bool adrenaline_rush) {
        l.setAdrenalineRush(adrenaline_rush);
    }

    void setLoaderSafeStowage(bool safe_stowage) {
        l.setSafeStowage(safe_stowage);
    }

    void setLoaderName(char* name) {
        l.setName(name);
    }

    void setLoaderLastName(char* last_name) {
        l.setLastName(last_name);
    }

    void setLoaderExperience(double experience) {
        l.setExperience(experience);
    }

    void setLoaderHeigth(double heigth) {
        l.setHeigth(heigth);
    }

    void setLoaderWeight(double weight) {
        l.setWeight(weight);
    }

    void setLoaderAge(int age) {
        l.setAge(age);
    }

    void setLoaderRepairs(bool repairs) {
        l.setRepairs(repairs);
    }

    void setLoaderConcealment(bool concealment) {
        l.setConcealment(concealment);
    }

    void setLoaderFirefighting(bool firefighting) {
        l.setFirefighting(firefighting);
    }

    void setLoaderBrothersInArms(bool brothers_in_arms) {
        l.setBrothersInArms(brothers_in_arms);
    }

    /*
    void setRadioOperator(bool saRadioOperator, bool covRadioOperator, bool sbRadioOperator, bool relRadioOperator, char* NameRadioOperator, char* LastNameRadioOperator, float expRadioOperator, float hRadioOperator, float wRadioOperator, int ageRadioOperator, bool repairsRadioOperator, bool conRadioOperator, bool firefightingRadioOperator, bool biaRadioOperator) {

        ro.setSituationalAwareness(saRadioOperator);
        ro.setCallOfVengeance(conRadioOperator);
        ro.setSignalBoosting(sbRadioOperator);
        ro.setRelaying(relRadioOperator);
        ro.setName(NameRadioOperator);
        ro.setLastName(LastNameRadioOperator);
        ro.setExperience(expRadioOperator);
        ro.setHeigth(hRadioOperator);
        ro.setWeight(wRadioOperator);
        ro.setAge(ageRadioOperator);
        ro.setRepairs(repairsRadioOperator);
        ro.setConcealment(conRadioOperator);
        ro.setFirefighting(firefightingRadioOperator);
        ro.setBrothersInArms(biaRadioOperator);
    }*/

    // Seteri za Radio Operator - a
    void setRadioOperatorSituationalAwareness(bool situational_awareness) {
        ro.setSituationalAwareness(situational_awareness);
    }

    void setRadioOperatorCallOfVengeance(bool call_of_vengeance) {
        ro.setCallOfVengeance(call_of_vengeance);
    }

    void setRadioOperatorSignalBoosting(bool signal_boosting) {
        ro.setSignalBoosting(signal_boosting);
    }

    void setRadioOperatorRelaying(bool relaying) {
        ro.setRelaying(relaying);
    }

    void setRadioOperatorName(char* name) {
        ro.setName(name);
    }

    void setRadioOperatorLastName(char* last_name) {
        ro.setLastName(last_name);
    }

    void setRadioOperatorExperience(double experience) {
        ro.setExperience(experience);
    }

    void setRadioOperatorHeigth(double heigth) {
        ro.setHeigth(heigth);
    }

    void setRadioOperatorWeight(double weight) {
        ro.setWeight(weight);
    }

    void setRadioOperatorAge(int age) {
        ro.setAge(age);
    }

    void setRadioOperatorRepairs(bool repairs) {
        ro.setRepairs(repairs);
    }

    void setRadioOperatorConcealment(bool concealment) {
        ro.setConcealment(concealment);
    }

    void setRadioOperatorFirefighting(bool firefighting) {
        ro.setFirefighting(firefighting);
    }

    void setRadioOperatorBrothersInArms(bool brothers_in_arms) {
        ro.setBrothersInArms(brothers_in_arms);
    }

    //GETERI ZA CREW

    // Commander geteri

    bool getCommanderMentor() const {
        return com.getMentor();
    }

    bool getCommanderRecon() const {
        return com.getRecon();
    }

    bool getCommanderJackOfAllTrades() const {
        return com.getJackOfAllTrades();
    }

    bool getCommanderEagleEye() const {
        return com.getEagleEye();
    }

    bool getCommanderSixthSense() const {
        return com.getSixthSense();
    }

    char* getCommanderName() {
        return com.getName();
    }

    char* getCommanderLastName() {
        return com.getLastName();
    }

    double getCommanderExperience() {
        return com.getExperience();
    }

    double getCommanderHeigth() {
        return com.getHeigth();
    }

    double getCommanderWeight() {
        return com.getWeight();
    }

    int getCommanderAge() {
        return com.getAge();
    }

    bool getCommanderRepairs() {
        return com.getRepairs();
    }

    bool getCommanderConcealment() {
        return com.getConcealment();
    }

    bool getCommanderFirefighting() {
        return com.getFirefighting();
    }

    bool getCommanderBrothersInArms() {
        return com.getBrothersInArms();
    }

    //Driver geteri

    bool getDriverControlledImpact() const {
        return d.getControlledImpact();
    }

    bool getDriverOffRoadDriving() const {
        return d.getOffRoadDriving();
    }

    bool getDriverSmoothRide() const {
        return d.getSmoothRide();
    }

    bool getDriverPreventativeMaintenance() const {
        return d.getPreventativeMaintenance();
    }

    bool getDriverClutchBraking() const {
        return d.getSmoothRide();
    }

    char* getDriverName() {
        return d.getName();
    }

    char* getDriverLastName() {
        return d.getLastName();
    }
    
    double getDriverExperience() const {
        return d.getExperience();
    }

    double getDriverHeigth()const {
        return d.getHeigth();
    }

    double getDriverWeight() const {
        return d.getWeight();
    }

    int getDriverAge() const {
        return d.getAge();
    }

    bool getDriverRepairs() const {
        return d.getRepairs();
    }

    bool getDriverConcealment() const {
        return d.getConcealment();
    }

    bool getDriverFirefighting() const {
        return d.getFirefighting();
    }

    bool getDriverBrothersInArms() const {
        return d.getBrothersInArms();
    }

    // Gunner geteri

    bool getGunnerDesignatedTarget() const {
        return g.getDesignatedTarget();
    }

    bool getGunnerArmorer() const {
        return g.getArmorer();
    }

    bool getGunnerDeadEye() const {
        return g.getDeadeye();
    }

    bool getGunnerSnapShot() const {
        return g.getSnapShot();
    }

    char* getGunnerName() {
        return g.getName();
    }

    char* getGunnerLastName() {
        return g.getLastName();
    }

    double getGunnerExperience() const {
        return g.getExperience();
    }

    double getGunnerHeigth() const {
        return g.getHeigth();
    }

    double getGunnerWeight() const {
        return g.getWeight();
    }

    int getGunnerAge() const {
        return g.getAge();
    }

    bool getGunnerRepairs() const {
        return g.getRepairs();
    }

    bool getGunnerConcealment() const {
        return g.getConcealment();
    }

    bool getGunnerFirefighting() const {
        return g.getFirefighting();
    }

    bool getGunnerBrothersInArms() const {
        return g.getBrothersInArms();
    }

    // Loader geteri

    bool getLoaderIntuition() const {
        return l.getIntuition();
    }

    bool getLoaderAdrenalineRush() const {
        return l.getAdrenalineRush();
    }

    bool getLoaderSafeStowage() const {
        return l.getSafeStowage();
    }

    char* getLoaderName() {
        return l.getName();
    }

    char* getLoaderLastName() {
        return l.getLastName();
    }

    double getLoaderExperience() const{
        return l.getExperience();
    }

    double getLoaderHeigth() const {
        return l.getHeigth();
    }

    double getLoaderWeight() const {
        return l.getWeight();
    }

    int getLoaderAge() const {
        return l.getAge();
    }

    bool getLoaderRepairs() const {
        return l.getRepairs();
    }

    bool getLoaderConcealment() const {
        return l.getConcealment();
    }

    bool getLoaderFirefighting() const {
        return l.getFirefighting();
    }

    bool getLoaderBrothersInArms() const {
        return l.getBrothersInArms();
    }

    // Radio Operator geteri

    bool getRadioOperatorSituationalAwareness() const {
        return ro.getSituationalAwareness();
    }

    bool getRadioOperatorCallOfVengeance() const {
        return ro.getCallOfVengeance();
    }

    bool getRadioOperatorSignalBoosting() const {
        return ro.getSignalBoosting();
    }

    bool getRadioOperatorRelaying() const {
        return ro.getRelaying();
    }

    char* getRadioOperatorName() {
        return ro.getName();
    }

    char* getRadioOperatorLastName() {
        return ro.getLastName();
    }

    double getRadioOperatorExperience() const{
        return ro.getExperience();
    }

    double getRadioOperatorHeigth() const {
        return ro.getHeigth();
    }

    double getRadioOperatorWeight() const {
        return ro.getWeight();
    }

    int getRadioOperatorAge() const {
        return ro.getAge();
    }

    bool getRadioOperatorRepairs() const {
        return ro.getRepairs();
    }

    bool getRadioOperatorConcealment() const {
        return ro.getConcealment();
    }

    bool getRadioOperatorFirefighting() const {
        return ro.getFirefighting();
    }

    bool getRadioOperatorBrothersInArms() const {
        return ro.getBrothersInArms();
    }

    friend std::ostream& operator<<(std::ostream& os, const Crew& c) {

        os << "CREW : " << std::endl;
        os << c.com;
        os << c.d;
        os << c.l;
        os << c.g;
        os << c.ro;

        return os;
    }
};



class Consumables{
 
private:

    FirstAidKitType first_slot;
    RepairKitType second_slot;
    FireExtinguisherType third_slot;
    OtherConsumables fourth_slot;

public:

    Consumables() {

        first_slot = FirstAidKitType :: SmallFirstAidKit;
        second_slot = RepairKitType :: LargeRepairKit;
        third_slot = FireExtinguisherType :: ManualFireExtinguisher;
        fourth_slot =OtherConsumables :: Coffe;
    }

    Consumables(FirstAidKitType AidKit, RepairKitType RepairKit, FireExtinguisherType FireExtinguisher, OtherConsumables consumables) {
       
        first_slot = AidKit;
        second_slot = RepairKit;
        third_slot = FireExtinguisher;
        fourth_slot = consumables;

    }

    Consumables(Consumables& consumables) {

        first_slot = consumables.first_slot;
        second_slot = consumables.second_slot;
        third_slot = consumables.third_slot;
        fourth_slot = consumables.fourth_slot;
    }
    
    void setFirstSlot(FirstAidKitType AidKit) {
        first_slot = AidKit;
    }

    void setSecondSlot(RepairKitType RepairKit) {
        second_slot = RepairKit;
    }

    void setThirdSlot(FireExtinguisherType FireExtinguisher) {
        third_slot = FireExtinguisher;
    }

    void setFourthSlot(OtherConsumables consumables) {
        fourth_slot = consumables;
    }

    FirstAidKitType getFirstSlot() const {
        return first_slot;
    }

    RepairKitType getSecondSlot() const {
        return second_slot;
    }

    FireExtinguisherType getThirdSlot() const {
        return third_slot;
    }

    OtherConsumables getFourthSlot() const {
        return fourth_slot;
    }

    friend std::ostream& operator<<(std::ostream& os, const Consumables& con) {
        
        os<<"CONSUMABLES : " << std::endl;
        os << "First slot: ";
        switch (con.first_slot)
        {
        case FirstAidKitType::SmallFirstAidKit:
            os<<"Small first aid kit" << std::endl;
            break;
        case FirstAidKitType::LargeFirstAidKit:
            os<<"Large first aid kit" << std::endl;
            break;
        }

        os << "Second slot : ";

        switch (con.second_slot)
        {
        case RepairKitType::SmallRepairKit:
            os<<"Small repair kit" << std::endl;
            break;
        case RepairKitType::LargeRepairKit:
            os<<"Large repair kit" << std::endl;
            break;
        
        }

        os << "Third slot : ";

        switch (con.third_slot)
        {
        case FireExtinguisherType::ManualFireExtinguisher:
            os<<"Manual fire extinguisher" << std::endl;
            break;
        case FireExtinguisherType::AutomaticFireExtinguisher:
            os<<"Automatic fire extinguisher" << std::endl;
            break;
        }

        os << "Fourth slot : ";

        switch (con.fourth_slot)
        {
        case OtherConsumables::Chocolate:
            os<<"Chocolate" << std::endl;
            break;
        case OtherConsumables::Coffe:
            os<<"Coffe" << std::endl;
            break;
        case OtherConsumables::Tea:
            os<<"Tea" << std::endl;
            break;
        }

        return os;
    }
};
/*
class ServiceRecord {

private:
    int NumberOfBatles;
    double ProcentOfVictories;
    double HitRatio;
    double AverageDamagePerBattle;
    double AverageExperiencePerBattle;
    int MaximumDestroyedInBattle; // Misli se na sve ukupno, rekord
    int NumberOfAceTanke; // Zlatno M
    double PersonalRating;
    int BattlesSurvived;
    double DamageRatio;
    double DestructionRatio;
    double ArmorUseEfficiency;
    double BaseCapturePoints;
    double BaseDefensePoints;
    int NumberOfEnemyVehiclesSpotted;
    int NumberOfEnemyVehiclesDestroyed;
    double MaxExperienceInBattle;
    double MaxDamageInBattle;
};*/



class Ammunition {

private:
    GrenadeType type;
    double damage;
    double penetration;
    double velocity;
    double weight;
    int NumberOfGrenades;
    int MaxCapacity;
    double MoneyForOneGrenade;

public:
    Ammunition() {
        type = GrenadeType::HESH;
        damage = 380.79;
        penetration = 320.67;
        velocity = 145.743;
        weight = 23.46;
        NumberOfGrenades = 12;
        MaxCapacity = 24;
        MoneyForOneGrenade = 1230.56;
    }

    Ammunition(GrenadeType Type, double Damage, double Penetration, double Velocity, double Weight, int number_of_grenades, int max_capacity, double money_for_one_grenade) {

        type = Type;
        damage = Damage;
        penetration = Penetration;
        velocity = Velocity;
        weight = Weight;
        NumberOfGrenades = number_of_grenades;
        MaxCapacity = max_capacity;
        MoneyForOneGrenade = money_for_one_grenade;
    }

    Ammunition(Ammunition& ammunation) {

        type = ammunation.type;
        damage = ammunation.damage;
        penetration = ammunation.penetration;
        velocity = ammunation.velocity;
        weight = ammunation.weight;
        NumberOfGrenades = ammunation.NumberOfGrenades;
        MaxCapacity = ammunation.MaxCapacity;
        MoneyForOneGrenade = ammunation.MoneyForOneGrenade;
    }

    void setType(GrenadeType Type){
        type = Type;
    }

    void setDamage(double Damage) {
        damage = Damage;
    }

    void setPenetration(double Penetration) {
        penetration = Penetration;
    }

    void setVelocity(double Velocity) {
        velocity = Velocity;
    }

    void setWeight(double Weight) {
        weight = Weight;
    }

    void setNumberOfGrenades(int Number) {
        NumberOfGrenades = Number;
    }

    void setMaxCapacity(int max_capacity) {
        MaxCapacity = max_capacity;
    }

    void setMoneyForOneGrenade(double money) {
        MoneyForOneGrenade = money;
    }

    GrenadeType getGrenadeType()const {
        return type;
    }

    double getDamage()const {
        return damage;
    }

    double getPenetration()const {
        return penetration;
    }

    double getVelocity()const {
        return velocity;
    }

    double getWeight()const {
        return weight;
    }

    int getNumberOfGrenades()const {
        return NumberOfGrenades;
    }

    int getMaxCapacity()const {
        return MaxCapacity;
    }

    double getMoneyForOneGrenade()const {
        return MoneyForOneGrenade;
    }

    friend std::ostream& operator<<(std::ostream& os, const Ammunition& am) {

        os<<"AMMUNITION : " << std::endl;
        os << "Grenade type : ";
        switch (am.type)
        {
        case GrenadeType::AP:
            os << "AP" << std::endl;
            break;
        case GrenadeType::APCR:
            os << "APCR" << std::endl;
            break;
        case GrenadeType::HE:
            os << "HE" << std::endl;
            break;
        case GrenadeType::HEAT:
            os << "HEAT" << std::endl;
            break;
        case GrenadeType::HESH:
            os << "HESH" << std::endl;
            break;
        }

        os << "Damage: " << am.damage << std::endl;
        os << "Penetration : " << am.penetration << std::endl;
        os << "Velocity : " << am.velocity << std::endl;
        os << "Weight : " << am.weight << std::endl;
        os << "Number of grenades : " << am.NumberOfGrenades << std::endl;
        os << "Max capacity : " << am.MaxCapacity << std::endl;
        os << "Money for one grenade : " << am.MoneyForOneGrenade << std::endl;

        return os;

    }
};
//Apstraktna klasa 
class TankModuo {

protected:

    double health;
    double weight;
    double heigth;
    double surface;
    double volume;

public:

    double getHealth()const {
        return health;
    }

    double getWeight()const {
        return weight;
    }

    double getHeight()const {
        return heigth;
    }

    double getSurface()const {
        return surface;
    }

    double getVolume()const {
        return volume;
    }

    void setHealth(double health_) {
        health = health_;
    }

    void setWeight(double weight_) {
        weight = weight_;
    }

    void setHeigth(double heigth_) {
        heigth = heigth_;
    }

    void setSurface(double surface_) {
        surface = surface_;
    }

    void setVolume(double volume_) {
        volume = volume_;
    }

    virtual void Fire() = 0;
};

class Radio : public TankModuo{

private:

    double range; // Koliko metara linijski 
    double radius; // radijus koji moze da cuje

public:

    Radio() {

        health = 200;
        weight = 120;
        heigth = 1.40;
        surface = 200;
        volume = 95;
        range = 1400.76;
        radius = 730.43;
    }

    Radio(double Range, double radiuss, double health_, double weight_, double heigth_, double surface_, double volume_) {
        
        health = health_;
        weight = weight_;
        heigth = heigth_;
        surface = surface_;
        volume = volume_;
        range = Range;
        radius = radiuss;
    }

    Radio(Radio& radio) {
       
        health = radio.health;
        weight = radio.weight;
        heigth = radio.heigth;
        surface = radio.surface;
        volume = radio.volume;
        range = radio.range;
        radius = radio.radius;
    }
    
    void setRange(double Range) {
        range = Range;
    }

    void setRadius(double Radius) {
        radius = Radius;
    }

    double getRange()const {
        return range;
    }

    double getRadius()const {
        return radius;
    }

    friend std::ostream& operator<<(std::ostream& os, const Radio& r) {

        os<<"RADIO :" << std::endl;
        os << "Health : " << r.health << std::endl;
        os << "Weight : " << r.weight << std::endl;
        os << "Heigth : " << r.heigth << std::endl;
        os << "Surface :" << r.surface << std::endl;
        os << "Volume : " << r.volume << std::endl;
        os << "Range : " << r.range << std::endl;
        os << "Radius :" << r.radius << std::endl;
       
        return os;
    }

private:
    void Fire() {

    }
};

class Track : public TankModuo{

private:

    double TraverseSpeed; // u stepenima
    double MaxLoad; // izdrzljivost nosenja 
    double durabillity;
    double length;
    int NumberOfParts;

public:

    Track() {

        health = 500;
        weight = 1320;
        heigth = 140.53;
        surface = 200;
        volume = 95;
        TraverseSpeed = 67.785;
        MaxLoad = 2567.43;
        durabillity = 45.32;
        weight = 300.57;
        length = 120.89;
        NumberOfParts = 112;
    }

    Track(double traverse_speed, double max_load, double Durabillity, double Length, int number_of_parts, double health_, double weight_, double heigth_, double surface_, double volume_ ) {

        health = health_;
        weight = weight_;
        heigth = heigth_;
        surface = surface_;
        volume = volume_;
        TraverseSpeed = traverse_speed;
        MaxLoad = max_load;
        durabillity = Durabillity;
        length = Length;
        NumberOfParts = number_of_parts;
    }

    Track(Track& track) {

        health = track.health;
        weight = track.weight;
        heigth = track.heigth;
        surface = track.surface;
        volume = track.volume;
        TraverseSpeed = track.TraverseSpeed;
        MaxLoad = track.MaxLoad;
        durabillity = track.durabillity;
        weight = track.weight;
        length = track.length;
        NumberOfParts = track.NumberOfParts;
    }

    void setTraverseSpeed(double traverse_speed) {

        TraverseSpeed = traverse_speed;
    }

    void setMaxLoad(double max_load) {
        
        MaxLoad = max_load;
    }

    void setDurabillity(double Durabillity) {

        durabillity = Durabillity;
    }

    void setWeight(double Weight) {

        weight = Weight;
    }

    void setLength(double Length) {

        length = Length;
    }

    void setNumberOfParts(int number_of_parts) {

        NumberOfParts = number_of_parts;
    }

    double getTraverseSpeed()const {
        return TraverseSpeed;
    }

    double getMaxLoad()const {
        return MaxLoad;
    }

    double getDurabillity()const {
        return durabillity;
    }

    double getWeight()const {
        return weight;
    }

    double getLength()const {
        return length;
    }

    int getNumberOfParts()const {
        return NumberOfParts;
    }

    friend std::ostream& operator<<(std::ostream& os, const Track& t) {
       
        os<<"TRACK: " << std::endl;
        os << "Traverse speed: " << t.TraverseSpeed << std::endl;
        os << "Max load: " << t.MaxLoad << std::endl;
        os << "Durability: " << t.durabillity << std::endl;
        os << "Length: " << t.length << std::endl;
        os << "Number of parts: " << t.NumberOfParts << std::endl;
        os << "Health : " << t.health << std::endl;
        os << "Weight : " << t.weight << std::endl;
        os << "Heigth : " << t.heigth << std::endl;
        os << "Surface :" << t.surface << std::endl;
        os << "Volume : " << t.volume << std::endl;
        return os;
    }

    private:
        void Fire() {

        }
};

class Motor : public TankModuo{

private:

    double power;
    double FireChance; // sanse da se zapali 
    double MaxSpeed;
    double MaxReverseSpeed;
    int NumberOfGears; // kasnije moze da se uvede funkcionalnost, primer kao sa kolima

public:

    Motor() {
        
        health = 600;
        weight = 1200;
        heigth = 3.05;
        surface = 1321;
        volume = 31;
        power = 56.79;
        FireChance = 32.897;
        weight = 320.41;
        MaxSpeed = 45.67;
        MaxReverseSpeed = 12.32;
        NumberOfGears = 5;
    }

    Motor(double Power, double fire_chance, double max_speed, double max_reverse_speed, int number_of_gears, double health_, double weight_, double heigth_, double surface_, double volume_) {
            
        health = health_;
        weight = weight_;
        heigth = heigth_;
        surface = surface_;
        volume = volume_;
        power = Power;
        FireChance = fire_chance;
        MaxSpeed = max_speed;
        MaxReverseSpeed = max_reverse_speed;
        NumberOfGears = number_of_gears;
    }

    Motor(Motor& motor) {

        health = motor.health;
        weight = motor.weight;
        heigth = motor.heigth;
        surface = motor.surface;
        volume = motor.volume;
        power = motor.power;
        FireChance = motor.FireChance;
        weight = motor.weight;
        MaxSpeed = motor.MaxSpeed;
        MaxReverseSpeed = motor.MaxReverseSpeed;
        NumberOfGears = motor.NumberOfGears;
    }

    void setPower(double Power) {
        power = Power;
    }

    void setFireChance(double fire_chance) {
        FireChance = fire_chance;
    }

    void setMaxSpeed(double max_speed) {
        MaxSpeed = max_speed;
    }

    void setMaxReverseSpeed(double max_reverse_speed) {
        MaxReverseSpeed = max_reverse_speed;
    }

    void setNumberOfGears(int number_of_gears) {
        NumberOfGears = number_of_gears;
    }

    double getPower()const {
        return power;
    }

    double getFireChance()const {
        return FireChance;
    }

    double getMaxSpeed()const {
        return MaxSpeed;
    }

    double getMaxReverseSpeed()const {
        return MaxReverseSpeed;
    }

    int getNumberOfGears()const {
        return NumberOfGears;
    }

    friend std::ostream& operator<<(std::ostream& os, const Motor& m) {

        os<<"MOTOR : " << std::endl;
        os << "Power : " << m.power << std::endl;
        os << "Fire chance: " << m.FireChance << std::endl;
        os << "Max speed: " << m.MaxSpeed << std::endl;
        os << "Max reverse speed: " << m.MaxReverseSpeed << std::endl;
        os << "Number of gears: " << m.NumberOfGears << std::endl;
        os << "Health : " << m.health << std::endl;
        os << "Weight : " << m.weight << std::endl;
        os << "Heigth : " << m.heigth << std::endl;
        os << "Surface :" << m.surface << std::endl;
        os << "Volume : " << m.volume << std::endl;
        return os;
    }

    private:
        void Fire() {

        }

};

class Dome : public TankModuo{

private:

    double Armor;
    double Rotation; // u stepenima
    double ViewRange;

public:

    Dome() {

        health = 600;
        weight = 124.532;
        heigth = 1.35;
        surface = 311.50;
        volume = 41;
        Armor = 459.32;
        Rotation = 276.31;
        ViewRange = 5043.245;
    }

    Dome(double armor, double RRotation, double View_Range, double health_, double weight_, double heigth_, double surface_, double volume_) {
        
        health = health_;
        weight = weight_;
        heigth = heigth_;
        surface = surface_;
        volume = volume_;
        Armor = armor;
        Rotation = RRotation;
        ViewRange = View_Range;
    }

    Dome(Dome& dome) {

        health = dome.health;
        weight = dome.weight;
        heigth = dome.heigth;
        surface = dome.surface;
        volume = dome.volume;
        Armor = dome.Armor;
        Rotation = dome.Rotation;
        ViewRange = dome.ViewRange;
    }

    void setArmor(double armor) {
        Armor = armor;
    }

    void setRotation(double rotation) {
        Rotation = rotation;
    }

    void setViewRange(double view_range) {
        ViewRange = view_range;
    }

    double getArmor()const {
        return Armor;
    }

    double getRotation()const {
        return Rotation;
    }

    double getViewRange()const {
        return ViewRange;
    }

    friend std::ostream& operator<<(std::ostream& os, const Dome& d) {

        os << "DOME: " << std::endl;
        os << "Armor: " << d.Armor << std::endl;
        os << "Rotation : " << d.Rotation << std::endl;
        os << "View range: " << d.ViewRange << std::endl;
        os << "Health : " << d.health << std::endl;
        os << "Weight : " << d.weight << std::endl;
        os << "Heigth : " << d.heigth << std::endl;
        os << "Surface :" << d.surface << std::endl;
        os << "Volume : " << d.volume << std::endl;
        return os;
    }

private:
    void Fire() {

    }

};

class Gun : public TankModuo{
 
private:

    double RateOfFire;
    double Penetration;
    double damage;
    double DispresionAt100m;
    double AimTime;
    double Accuracy;
    double RoundsMin;
    double Reload;
    GrenadeType Grenade; 

public:

    Gun() {
        
        health = 2000;
        weight = 141.56;
        heigth = 1.010;
        surface = 670;
        volume = 900;
        RateOfFire = 228.59;
        Penetration = 320.56;
        damage = 450.98;
        DispresionAt100m = 0.5;
        AimTime = 14.16;
        Accuracy = 78.22;
        RoundsMin = 2;
        Reload = 16.14;
        Grenade = GrenadeType::APCR;
    }

    Gun(double rate_of_fire, double penetration, double Damage, double Dispresion_at_100m, double aim_time, double accuracy, double rounds_min, double reload, GrenadeType grenade, double health_, double heigth_, double weight_, double surface_, double volume_) {

        health = health_;
        weight = weight_;
        heigth = heigth_;
        surface = surface_;
        volume = volume_;
        RateOfFire = rate_of_fire;
        Penetration = penetration;
        damage = Damage;
        DispresionAt100m = Dispresion_at_100m;
        AimTime = aim_time;
        Accuracy = accuracy;
        RoundsMin = rounds_min;
        Reload = reload;
        Grenade = grenade;
    }

    Gun(Gun& gun) {

        health = gun.health;
        weight = gun.weight;
        heigth = gun.heigth;
        surface = gun.surface;
        volume = gun.volume;
        RateOfFire = gun.RateOfFire;
        Penetration = gun.Penetration;
        damage = gun.damage;
        DispresionAt100m = gun.DispresionAt100m;
        AimTime = gun.AimTime;
        Accuracy = gun.Accuracy;
        RoundsMin = gun.RoundsMin;
        Reload = gun.Reload;
        Grenade = gun.Grenade;
    }

    void setRateOfFire(double rate_of_fire) {
        RateOfFire = rate_of_fire;
    }

    void setPenetration(double penetration) {
        Penetration = penetration;
    }

    void setDamage(double Damage) {
        damage = Damage;
    }

    void setDispresionAt100m(double dispresion_at_100m) {
        DispresionAt100m = dispresion_at_100m;
    }

    void setAimTime(double aim_time) {
        AimTime = aim_time;
    }

    void setAccuracy(double accuracy) {
        Accuracy = accuracy;
    }

    void setRoundsMin(double rounds_min) {
        RoundsMin = rounds_min;
    }

    void setReload(double reload) {
        Reload = reload;
    }

    void setGrenade(GrenadeType grenade) {
        Grenade = grenade;
    }

    double getRateOfFire()const {
        return RateOfFire;
    }

    double getPenetration()const {
        return Penetration;
    }

    double getDamage()const {
        return damage;
    }

    double getDispresionAt100m()const {
        return DispresionAt100m;
    }

    double getAimTime()const {
        return AimTime;
    }

    double getAccuracy()const {
        return Accuracy;
    }

    double getRoundsMin()const {
        return RoundsMin;
    }

    double getReload()const {
        return Reload;
    }

    GrenadeType getGrenade()const {
        return Grenade;
    }

    friend std::ostream& operator<<(std::ostream& os, const Gun& g) {

        os << "GUN: " << std::endl;
        os << "Rate of fire: " << g.RateOfFire << std::endl;
        os << "Penetration: " << g.Penetration << std::endl;
        os << "Damage : " << g.damage;
        os << "Dispresion at 100 m : " << g.DispresionAt100m << std::endl;
        os << "Aim time : " << g.AimTime << std::endl;
        os << "Accuracy : " << g.Accuracy << std::endl;
        os << "Rounds per min : " << g.RoundsMin << std::endl;
        os << "Reload : " << g.Reload << std::endl;
        os << "Grenade type: ";
        
        switch (g.Grenade)
        {
        case GrenadeType::AP:
            os<<"AP"<< std::endl;
            break;
        case GrenadeType::APCR:
            os << "APCR" << std::endl;
            break;
        case GrenadeType::HE:
            os << "HE" << std::endl;
            break;
        case GrenadeType::HEAT:
            os << "HEAT" << std::endl;
            break;
        case GrenadeType::HESH:
            os << "HESH" << std::endl;
            break;
        }
        os << "Health : " << g.health << std::endl;
        os << "Weight : " << g.weight << std::endl;
        os << "Heigth : " << g.heigth << std::endl;
        os << "Surface :" << g.surface << std::endl;
        os << "Volume : " << g.volume << std::endl;

        return os;
    }

    private:
    void Fire() {

    }
};


class Tank{

private:

    char TankName[MAX_SIZE_FOR_NAME];
    Tier tier;
    Nation nation;
    double experience;
    double SilverCoins;
    double Gold;
    double VeteranExperience;
    double CostMoney; // zelene novcanice, nova valuta
    double health;

public:

    /// Na public, da bih mogao da koristim setere i getere od njih, a ne da pravim nove

    Gun gun;
    Dome dome;
    Motor motor;
    Track track;
    Radio radio;
    Ammunition ammunition;
    Consumables consumables;
    Crew crew;
    
public:
    
    Tank() {
        
        strcpy_s(TankName, "Tiger II");
        tier = VIII;
        nation = Nation::GERMANY;
        gun = Gun();
        dome = Dome();
        motor = Motor();
        track = Track();
        radio = Radio();
        health = 3600;
        ammunition = Ammunition();
        consumables = Consumables();
        crew = Crew();
        experience = 36984.56;
        SilverCoins = 500896.34;
        Gold = 300;
        VeteranExperience = 15984.12;
        CostMoney = 22;
    }

    Tank(char* tank_name,int tierr, int nationn, double experiencee, double silver_coins, double goldd, double veteran_experience, double cost_moneyy) {
        
        strcpy_s(TankName, tank_name);

        tier = (Tier)tierr;
        nation = (Nation)nationn;

        gun = Gun();
        dome = Dome();
        motor = Motor();
        track = Track();
        radio = Radio();
        health = 3600;
        ammunition = Ammunition();
        consumables = Consumables();
        crew = Crew();

        experience = experiencee;
        SilverCoins = silver_coins;
        Gold = goldd;
        VeteranExperience = veteran_experience;
        CostMoney = cost_moneyy;
    }

    Tank(const Tank& tank) {
        
        strcpy_s(TankName, tank.TankName);
        tier = tank.tier;
        nation = tank.nation;
        gun = tank.gun;
        dome = tank.dome;
       // dome.setArmor(tank.dome.getArmor()); - drugi nacin 
        motor = tank.motor;
        track = tank.track;
        radio = tank.radio;
        health = tank.health;
        ammunition = tank.ammunition;
        consumables = tank.consumables;
        crew = tank.crew;
        experience = tank.experience;
        SilverCoins = tank.SilverCoins;
        Gold = tank.Gold;
        VeteranExperience = tank.experience;
        CostMoney = tank.CostMoney;
    }

    void setTankName(char* tank_name) {
        strcpy_s(TankName, tank_name);
    }

    void setTier(int tierr) {
        tier = (Tier)tierr;
    }

    void setNation(int nationn) {
        nation = (Nation)(nationn);
    }

    void setExperience(double experiencee) {
        experience = experiencee;
    }

    void setSilverCoins(double silver_coins) {
        SilverCoins = silver_coins;
    }

    void setGold(double gold_coins) {
        Gold = gold_coins;
    }

    void setVeteranExperience(double veteran_experience) {
        VeteranExperience = veteran_experience;
    }

    void setCostMoney(double cost_money) {
        CostMoney = cost_money;
    }

    char* getTankName() {
        return TankName;
    }

    Tier getTier()const {
        return tier;
    }

    Nation getNation()const {
        return nation;
    }

    double getExperience()const {
        return experience;
    }

    double getSilverCoins()const {
        return SilverCoins;
    }

    double getGold()const {
        return Gold;
    }

    double getVeteranExperience()const {
        return VeteranExperience;
    }

    double getCostMoney()const {
        return CostMoney;
    }

    friend std::ostream& operator<< (std::ostream& os, const Tank& t) {

        os << "Tank name is: " << t.TankName <<std::endl;
        os << "Tank tier is: " << t.tier + 1 << std::endl;
        os << "Nation of tank is: ";
        switch (t.nation)
        {
        case Nation::GERMANY:
            os<<"GERMANY"<< std::endl;
            break;
        case Nation::CHINA:
            os << "CHINA" << std::endl;
            break;
        case Nation::CZECHOSLOVAKIA:
            os << "CZECHOSLOVAKIA" << std::endl;
            break;
        case Nation::FRANCE:
            os << "FRANCE" << std::endl;
            break;
        case Nation::ITALY:
            os << "ITALY" << std::endl;
            break;
        case Nation::JAPAN:
            os << "JAPAN" << std::endl;
            break;
        case Nation::POLAND:
            os << "POLAND" << std::endl;
            break;
        case Nation::SWEDEN:
            os << "SWEDEN" << std::endl;
            break;
        case Nation::UK:
            os << "UK" << std::endl;
            break;
        case Nation::USA:
            os << "USA" << std::endl;
            break;
        case Nation::USSR:
            os << "USSR" << std::endl;
            break;
        }
        
        os<<"Tank Gun is: " << t.gun << std::endl;
        os<<"Tank Dome is: " << t.dome << std::endl;
        os<<"Tank Track is: " << t.track << std::endl;
        os<<"Tank Radio is: " << t.radio << std::endl;
        os<<"Tank Motor is: " << t.motor << std::endl;

        os << "Tank's health: " << t.health << std::endl;
        os << "Amunition of tank is: " << t.ammunition << std::endl;
        os << "Consumables of tank is: " << t.consumables << std::endl;
        os << "Crew of tank is: " << t.crew << std::endl;
        

        os<< "Experience of tank is : " << t.experience << std::endl;
        os << "Silver coins of tank are: " << t.SilverCoins<< std::endl;
        os << "Tank's gold: " << t.Gold << std::endl;
        os << "Veteran experience: " << t.VeteranExperience<< std::endl;
        os << "Cost money: " << t.CostMoney << std::endl;

        return os;
    }
        
};

class Platoon {

private:

    int NumberOfPlayers;
    TypeOfBattle battle;
    double BonusExperience;
    double BonusSilverCoins; 
    int PlatoonNumber; // Koji su platun po redu
    PlatoonChat chat;
    PlatoonVoiceChat VoiceChat;

public:
    
    std::list <Tank> tank;
    // std :: list <Tank> :: iterator it = tank.begin() + broj tenka koje hocu ; 1 - za drugog tenka 

public:

    Platoon() {

        NumberOfPlayers = 2;
        battle = TypeOfBattle :: RandomBattle;
        BonusExperience = 475.321;
        BonusSilverCoins = 2541.789;
        PlatoonNumber = 3;
        chat = PlatoonChat :: Enabled;
        VoiceChat = PlatoonVoiceChat :: EnabledVoice;
        tank.push_back(Tank());
        tank.push_back(Tank());
        
    }

    Platoon(int number_of_players ,int battlee, double bonus_experience, double bonus_money, int platoon_number, int Chat, int voice_chat, Tank tank1, Tank tank2, std::list<Tank> t) {
        
        while (number_of_players > 3 || number_of_players < 2) {

            std::cin >> number_of_players;
        }
        
        NumberOfPlayers = number_of_players;
        battle = (TypeOfBattle)battlee;
        BonusExperience = bonus_experience;
        BonusSilverCoins = bonus_money;
        PlatoonNumber = platoon_number;
        chat = (PlatoonChat)Chat;
        VoiceChat = (PlatoonVoiceChat)voice_chat;
        tank = t;
        
    }

    Platoon(const Platoon& platoon) {

        NumberOfPlayers = platoon.NumberOfPlayers;
        int i;
        battle = platoon.battle;
        BonusExperience = platoon.BonusExperience;
        BonusSilverCoins = platoon.BonusSilverCoins;
        PlatoonNumber = platoon.PlatoonNumber;
        chat = platoon.chat;
        VoiceChat = platoon.VoiceChat;
        i = 0;
        tank = platoon.tank;
    }

    void setNumberOfPlayers(int number_of_players) {
        
        if (number_of_players > 3 || number_of_players < 2) {
            std::cout << "Uneti broj igraca ne odgovara, uslov nije ispunjen !" << std::endl;
            return;
        }

        NumberOfPlayers = number_of_players;
    }

    void setBattleType(int battle_type) {
        if (battle_type < 0 || battle_type > 5) {
            std::cout << "Uneli ste neodgovarajuci broj ! " << std::endl;
            return;
        }
        battle = (TypeOfBattle)battle_type;
    }

    void setBonusExperience(double bonus_experience) {
        if(bonus_experience < 0 || bonus_experience > 2500){
            std::cout << "Uneli ste neodgovarajuci broj ! " << std::endl;
            return;
        }
        BonusExperience = bonus_experience;
    }

    void setBonusSilverCoins(double bonus_silver_coins) {
        if (bonus_silver_coins < 0 || bonus_silver_coins > 5000) {
            std::cout << "Uneli ste neodgovarajuci broj ! " << std::endl;
            return;
        }

        BonusSilverCoins = bonus_silver_coins;
    }

    void setPlatoonNumber(int platoon_number) {
        if (platoon_number < 1 || platoon_number > 7) {
            std::cout << "Uneli ste neodgovarajuci broj ! " << std::endl;
            return;
        }

        PlatoonNumber = platoon_number;
    }

    void setPlatoonChat(int platoon_chat) {
        if (platoon_chat < 0 || platoon_chat > 1) {
            std::cout << "Uneli ste neodgovarajuci broj ! " << std::endl;
            return;
        }

        chat = (PlatoonChat)(platoon_chat);
    }

    void setPlatoonVoiceChat(int platoon_voice_chat) {
        if (platoon_voice_chat < 0 || platoon_voice_chat > 1) {
            std::cout << "Uneli ste neodgovarajuci broj ! " << std::endl;
            return;
        }

        VoiceChat = (PlatoonVoiceChat)(platoon_voice_chat);
    }

    int getNumberOfPlayers()const {
        return NumberOfPlayers;
    }

    TypeOfBattle getBattleType()const {
        return battle;
    }

    double getBonusExperience()const {
        return BonusExperience;
    }

    double getBonusSilverCoins()const {
        return BonusSilverCoins;
    }

    int getPlatoonNumber()const {
        return PlatoonNumber;
    }

    PlatoonChat getPlatoonChat()const {
        return chat;
    }

    PlatoonVoiceChat getPlatoonVoiceChat()const {
        return VoiceChat;
    }

    friend std::ostream& operator<<(std::ostream& os, const Platoon& p) {

        os << "PLATOON : " << std::endl;
        os << "Number of players : " << p.NumberOfPlayers << std::endl;
        os << "Battle type : ";
        
        switch (p.battle)
        {
        case TypeOfBattle::RandomBattle:
            os << "Random Battle" << std::endl;
            break;
        case TypeOfBattle::RankedBattle:
            os << "Ranked Battle" << std::endl;
            break;
        case TypeOfBattle::SpecialBattle:
            os << "Special Battle" << std::endl;
            break;
        case TypeOfBattle::SteelHunter:
            os << "Steel Hunter" << std::endl;
            break;
        case TypeOfBattle::Stronghold:
            os << "Stronghold " << std::endl;
            break;
        case TypeOfBattle::TeamTraining:
            os << "Team Training" << std::endl;
            break;
        }

        os << "Bonus experience : " << p.BonusExperience << std::endl;
        os << "Bonus silver coins : " << p.BonusSilverCoins << std::endl;
        os << "Platoon number : " << p.PlatoonNumber << std::endl;
        os << "Platoon chat : ";
        switch (p.chat)
        {
        case PlatoonChat::Enabled:
            os << "Enabled" << std::endl;
            break;
        case PlatoonChat::NotEnabled:
            os << "Disabled/ Not enabled" << std::endl;
            break;
        }

        os << "Platoon voice chat : ";

        switch (p.VoiceChat)
        {
        case PlatoonVoiceChat::EnabledVoice:
            os << "Enabled" << std::endl;
            break;
        case PlatoonVoiceChat::NotEnabledVoice:
            os << "Not enabled" << std::endl;
            break;
        }

        std::list <Tank> ::const_iterator it = p.tank.begin(); // iterator je pokazivac na Tank
        for (; it != p.tank.end(); it++) {
            os << *it; // dereferenciram pokazivac na tenka da bih dobio tenka;
        }

        return os;
    }
};

class ScoreBoard {

private:

    double health_team1;
    double health_team2;
    int NumberOfPlatoons_team1;
    int NumberOfPlatoons_team2;

public:

    std::list<Tank> team1;
    std::list<Tank> team2;
    std::list <Platoon> Pteam1;
    std::list <Platoon> Pteam2;
    

public:

    ScoreBoard() {

        health_team1 = 42500;
        health_team2 = 39670;
        NumberOfPlatoons_team1 = 4;
        NumberOfPlatoons_team2 = 3;

        int i = 0;
        
        for (i = 0; i < 15; i++) {
            team1.push_back(Tank());
            team2.push_back(Tank());
        }

        for (i = 0; i < NumberOfPlatoons_team1; i++) {
            Pteam1.push_back(Platoon());
             
        }
        std::list <Platoon> ::iterator ip = Pteam1.begin();
        std::list <Tank> ::iterator it = team1.begin();

        for (i = 0; i < NumberOfPlatoons_team1; i++,ip++) {
            ip->tank.clear();
            for (int j = 0; j < ip->getNumberOfPlayers(); j++, it++) {
                ip->tank.push_back(*it);
            }

        }

        for (i = 0; i < NumberOfPlatoons_team2; i++) {
            Pteam2.push_back(Platoon());
        }

        std::list <Platoon> ::iterator ip2 = Pteam2.begin();
        std::list <Tank> ::iterator it2 = team2.begin();

        for (i = 0; i < NumberOfPlatoons_team2; i++, ip2++) {
            ip2->tank.clear();
            for (int j = 0; j < ip2->getNumberOfPlayers(); j++, it2++) {
                ip2->tank.push_back(*it2);
            }
        }

        
    }

    ScoreBoard(double health1, double health2, int platoon_team1, int platoon_team2, std::list<Tank> t1, std::list<Tank> t2, std::list <Platoon> pt1, std::list <Platoon> pt2){

        health_team1 = health1;
        health_team2 = health2;
        NumberOfPlatoons_team1 = platoon_team1;
        NumberOfPlatoons_team2 = platoon_team2;

        team1 = t1;
        team2 = t2;
        Pteam1 = pt1;
        Pteam2 = pt2;
    }

    ScoreBoard(const ScoreBoard& score_board) {

        health_team1 = score_board.health_team1;
        health_team2 = score_board.health_team2;
        NumberOfPlatoons_team1 = score_board.NumberOfPlatoons_team1;
        NumberOfPlatoons_team2 = score_board.NumberOfPlatoons_team2;

        team1 = score_board.team1;
        team2 = score_board.team2;
        Pteam1 = score_board.Pteam1;
        Pteam2 = score_board.Pteam2;
    }

    void setHealthForTeam1(double health){
        health_team1 = health;
    }

    void setHealthForTeam2(double health2) {
        health_team2 = health2;
    }

    void setNumbersOfPlatoon1(int number_of_platoon) {
        NumberOfPlatoons_team1 = number_of_platoon;
    }

    void setNumbersOfPlatoon2(int number_of_platoon2) {
        NumberOfPlatoons_team2 = number_of_platoon2;
    }

    void setTeam1(std::list<Tank> t) {
        team1 = t;
    }
    
    void setTeam2(std::list<Tank> t) {
        team2 = t;
    }

    void setPlatoonArray1(std::list<Platoon> p) {
        Pteam1 = p;
    }

    void setPlatoonArray2(std::list<Platoon> p) {
        Pteam2 = p;
    }

    double getHealthForTeam1()const {
        return health_team1;
    }

    double getHealthForTeam2()const {
        return health_team2;
    }

    int getNumbersOfPlatoon1()const {
        return NumberOfPlatoons_team1;
    }

    int getNumbersOfPlatoon2()const {
        return NumberOfPlatoons_team2;
    }

    std::list<Tank> getTeam1()const {
        return team1;
    }

    std::list<Tank> getTeam2()const {
        return team2;
    }

    std::list<Platoon> getPlatoonArrays1()const {
        return Pteam1;
    }

    std::list<Platoon> getPlatoonArrays2()const {
        return Pteam2;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const ScoreBoard& score_board) {

        os << "SCORE BOARD : " << std::endl;
        os << "Team 1 - health : " << score_board.health_team1 << std::endl;
        os << "Team 2 - health : " << score_board.health_team2 << std::endl;
        os << "Number of platoons in team 1 : " << score_board.NumberOfPlatoons_team1 << std::endl;
        os << "Number of platoons in team 2 : " << score_board.NumberOfPlatoons_team2 << std::endl;
        os << "TEAM 1: " << std::endl;

        std::list<Tank> ::const_iterator it = score_board.team1.begin();
        for (; it != score_board.team1.end(); it++) {
            os << *it << std::endl;
        }

        os << "TEAM 2 : " << std::endl;

        std::list<Tank> ::const_iterator it2 = score_board.team2.begin();
        for (; it2 != score_board.team2.end(); it2++) {
            os << *it2 << std::endl;
        }

        os << "Platoons - team 1 : " << std::endl;

        std::list<Platoon> ::const_iterator ip = score_board.Pteam1.begin();
        for (; ip != score_board.Pteam1.end(); ip++) {
            os << *ip << std::endl;;
        }

        os << "Platoons - team 2 : " << std::endl;

        std::list<Platoon> ::const_iterator ip2 = score_board.Pteam2.begin();
        for (; ip2 != score_board.Pteam2.end(); ip2++) {
            os << *(ip2) << std::endl;
        }

        os << std::endl;

        return os;
    }
};

class Matchmaking {

private:

    int BaseCapturePoints_team1;
    int BaseCapturePoints_team2;
    int BaseDefensePoints_team1;
    int BaseDefensePoints_team2;
    int NumberOfEnemyVehiclesSpotted_team1;
    int NumberOfEnemyVehiclesDestroyed_team1;
    int NumberOfEnemyVehiclesSpotted_team2;
    int NumberOfEnemyVehiclesDestroyed_team2;
    double AverageDamageInBattle_team1;
    double AverageDamageInBattle_team2;
    double AverageExperienceInBattle_team1;
    double AverageExperienceInBattle_team2;
    double MaxExperienceInBattle_team1;
    double MaxExperienceInBattle_team2;
    double MaxDamageInBattle_team1;
    double MaxDamageInBattle_team2;

public:

    ScoreBoard score_board;
    

public:

    Matchmaking() {

        BaseCapturePoints_team1 = 53;
        BaseCapturePoints_team2 = 23;
        BaseDefensePoints_team1 = 40;
        BaseDefensePoints_team2 = 50;
        NumberOfEnemyVehiclesSpotted_team1 = 3;
        NumberOfEnemyVehiclesSpotted_team2 = 1;
        NumberOfEnemyVehiclesDestroyed_team1 = 4;
        NumberOfEnemyVehiclesDestroyed_team2 = 5;
        AverageDamageInBattle_team1 = 1543;
        AverageDamageInBattle_team2 = 433;
        AverageExperienceInBattle_team1 = 2500;
        AverageExperienceInBattle_team2 = 507.53;
        MaxExperienceInBattle_team1 = 3000.540;
        MaxExperienceInBattle_team2 = 1200.321;
        MaxDamageInBattle_team1 = 5000.89;
        MaxDamageInBattle_team2 = 2700.421;

        score_board = ScoreBoard();
    }

    Matchmaking(int base_capture_points_team1, int base_capture_points_team2, int base_defense_points_team1, int base_defense_points_team2, int NNumberOfEnemyVehiclesSpotted_team1, int NNumberOfEnemyVehiclesSpotted_team2, int NNumberOfEnemyVehiclesDestroyed_team1, int NNumberOfEnemyVehiclesDestroyed_team2, double AAverageDamageInBattle_team1, double AAverageDamageInBattle_team2, double AAverageExperienceInBattle_team1, double AAverageExperienceInBattle_team2, double MMaxExperienceInBattle_team1, double MMaxExperienceInBattle_team2, double MMaxDamageInBattle_team1, double MMaxDamageInBattle_team2, ScoreBoard score_board_){

        BaseCapturePoints_team1 = base_capture_points_team1;
        BaseCapturePoints_team2 = base_capture_points_team2;
        BaseDefensePoints_team1 = base_capture_points_team1;
        BaseDefensePoints_team2 = base_capture_points_team2;
        NumberOfEnemyVehiclesSpotted_team1 = NNumberOfEnemyVehiclesSpotted_team1;
        NumberOfEnemyVehiclesSpotted_team2 = NNumberOfEnemyVehiclesSpotted_team2;
        NumberOfEnemyVehiclesDestroyed_team1 = NNumberOfEnemyVehiclesDestroyed_team1;
        NumberOfEnemyVehiclesDestroyed_team2 = NNumberOfEnemyVehiclesDestroyed_team2;
        AverageDamageInBattle_team1 = AAverageDamageInBattle_team1;
        AverageDamageInBattle_team2 = AAverageDamageInBattle_team2;
        AverageExperienceInBattle_team1 = AAverageExperienceInBattle_team1;
        AverageExperienceInBattle_team2 = AAverageExperienceInBattle_team2;
        MaxExperienceInBattle_team1 = MMaxExperienceInBattle_team1;
        MaxExperienceInBattle_team2 = MMaxExperienceInBattle_team2;
        MaxDamageInBattle_team1 = MMaxDamageInBattle_team1;
        MaxDamageInBattle_team2 = MMaxDamageInBattle_team2;
        
        score_board = ScoreBoard(score_board_);
    }

    Matchmaking(const Matchmaking& matchmaking) {

        BaseCapturePoints_team1 = matchmaking.BaseCapturePoints_team1;
        BaseCapturePoints_team2 = matchmaking.BaseCapturePoints_team2;
        BaseDefensePoints_team1 = matchmaking.BaseDefensePoints_team1;
        BaseDefensePoints_team2 = matchmaking.BaseDefensePoints_team2;
        NumberOfEnemyVehiclesSpotted_team1 = matchmaking.NumberOfEnemyVehiclesSpotted_team1;
        NumberOfEnemyVehiclesSpotted_team2 = matchmaking.NumberOfEnemyVehiclesDestroyed_team2;
        NumberOfEnemyVehiclesDestroyed_team1 = matchmaking.NumberOfEnemyVehiclesDestroyed_team1;
        NumberOfEnemyVehiclesDestroyed_team2 = matchmaking.NumberOfEnemyVehiclesDestroyed_team2;
        AverageDamageInBattle_team1 = matchmaking.AverageDamageInBattle_team1;
        AverageDamageInBattle_team2 = matchmaking.AverageDamageInBattle_team2;
        AverageExperienceInBattle_team1 = matchmaking.AverageExperienceInBattle_team1;
        AverageExperienceInBattle_team2 = matchmaking.AverageExperienceInBattle_team2;
        MaxExperienceInBattle_team1 = matchmaking.MaxExperienceInBattle_team1;
        MaxExperienceInBattle_team2 = matchmaking.MaxExperienceInBattle_team2;
        MaxDamageInBattle_team1 = matchmaking.MaxDamageInBattle_team1;
        MaxDamageInBattle_team2 = matchmaking.MaxDamageInBattle_team2;

        score_board = ScoreBoard(matchmaking.score_board);
    }

    //Seteri za Matchmaking 
    
    void setBaseCapturePointsTeam1(int base_capture_points_team1) {
        BaseCapturePoints_team1 = base_capture_points_team1;
    }

    void setBaseCapturePointsTeam2(int base_capture_points_team2) {
        BaseCapturePoints_team2 = base_capture_points_team2;
    }

    void setBaseDefensePointsTeam1(int base_defense_points_team1) {
        BaseDefensePoints_team1 = base_defense_points_team1;
    }

    void setBaseDefensePointsTeam2(int base_defense_points_team2) {
        BaseDefensePoints_team2 = base_defense_points_team2;
    }

    void setNumberOfEnemyVehiclesSpotted_team1(int number_of_vehicles_spotted_team1) {
        NumberOfEnemyVehiclesSpotted_team1 = number_of_vehicles_spotted_team1;
    }

    void setNumberOfEnemyVehiclesSpotted_team2(int number_of_vehicles_spotted_team2) {
        NumberOfEnemyVehiclesSpotted_team2 = number_of_vehicles_spotted_team2;
    }

    void setNumberOfEnemyVehiclesDestroyed_team1(int number_of_enemy_vehicles_destroyed_team1) {
        NumberOfEnemyVehiclesDestroyed_team1 = number_of_enemy_vehicles_destroyed_team1;
    }

    void setNumberOfEnemyVehiclesDestroyed_team2(int number_of_enemy_vehicles_destroyed_team2) {
        NumberOfEnemyVehiclesDestroyed_team2 = number_of_enemy_vehicles_destroyed_team2;
    }

    void setAverageDamageInBattle_team1(double average_damage_in_battle_team1) {
        AverageDamageInBattle_team1 = average_damage_in_battle_team1;
    }

    void setAverageDamageInBattle_team2(double average_damage_in_battle_team2) {
        AverageDamageInBattle_team2 = average_damage_in_battle_team2;
    }

    void setAverageExperienceInBattle_team1(double average_experience_in_battle_team1) {
        AverageExperienceInBattle_team1 = average_experience_in_battle_team1;
    }

    void setAverageExperienceInBattle_team2(double average_experience_in_battle_team2) {
        AverageExperienceInBattle_team2 = average_experience_in_battle_team2;
    }

    void setMaxExperienceInBattle_team1(double max_experience_team1) {
        MaxExperienceInBattle_team1 = max_experience_team1;
    }

    void setMaxExperienceInBattle_team2(double max_experience_team2) {
        MaxExperienceInBattle_team2 = max_experience_team2;
    }

    void setMaxDamageInBattle_team1(double max_damage_in_battle_team1) {
        MaxDamageInBattle_team1 = max_damage_in_battle_team1;
    }

    void setMaxDamageInBattle_team2(double max_damage_in_battle_team2) {
        MaxDamageInBattle_team2 = max_damage_in_battle_team2;
    }

    // Geteri za Matchmaking

    int getBaseCapturePointsTeam1()const {
        return BaseCapturePoints_team1;
    }

    int getBaseCapturePointsTeam2()const {
        return BaseCapturePoints_team2;
    }

    int getBaseDefensePointsTeam1()const {
        return BaseDefensePoints_team1;
    }

    int getBaseDefensePointsTeam2()const {
        return BaseDefensePoints_team2;
    }

    int getNumberOfEnemyVehiclesSpotted_team1()const {
        return NumberOfEnemyVehiclesSpotted_team1;
    }
    
    int getNumberOfEnemyVehiclesSpotted_team2()const {
        return NumberOfEnemyVehiclesSpotted_team2;
    }

    int getNumberOfEnemyVehiclesDestroyed_team1()const {
        return NumberOfEnemyVehiclesDestroyed_team1;
    }

    int getNumberOfEnemyVehiclesDestroyed_team2()const {
        return NumberOfEnemyVehiclesDestroyed_team2;
    }

    double getAverageDamageInBattle_team1()const {
        return AverageDamageInBattle_team1;
    }

    double getAverageDamageInBattle_team2()const {
        return AverageDamageInBattle_team2;
    }

    double getAverageExperienceInBattle_team1()const {
        return AverageExperienceInBattle_team1;
    }

    double getAverageExperienceInBattle_team2()const {
        return AverageExperienceInBattle_team2;
    }

    double getMaxExperienceInBattle_team1()const {
        return MaxDamageInBattle_team1;
    }

    double getMaxExperienceInBattle_team2()const {
        return MaxDamageInBattle_team2;
    }

    double getMaxDamageInBattle_team1()const {
        return MaxDamageInBattle_team1;
    }

    double getMaxDamageInBattle_team2()const {
        return MaxDamageInBattle_team2;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matchmaking& matchmaking) {

        os <<"*******************************************************************"<<std::endl;
        os << "MATCHMAKING : " << std::endl;
        os << "Base capture points - team 1 : " << matchmaking.BaseCapturePoints_team1 << std::endl;
        os << "Base capture points - team 2 : " << matchmaking.BaseCapturePoints_team2 << std::endl;
        os << "Base Defense capture points - team 1 : " << matchmaking.BaseDefensePoints_team1 << std::endl;
        os << "Base Defense capture points - team 2 : " << matchmaking.BaseDefensePoints_team2 << std::endl;
        os << "Number Of Enemy Vehicles Spotted - team 1 : " << matchmaking.NumberOfEnemyVehiclesSpotted_team1 << std::endl;
        os << "Number Of Enemy Vehicles Spotted - team 2 : " << matchmaking.NumberOfEnemyVehiclesSpotted_team2 << std::endl;
        os << "Number of enemy vehicles destroyed - team 1 : " << matchmaking.NumberOfEnemyVehiclesDestroyed_team1 << std::endl;
        os << "Number of enemy vehicles destroyed - team 2 : " << matchmaking.NumberOfEnemyVehiclesDestroyed_team1 << std::endl;
        os << "Average damage in Battle - team1 : " << matchmaking.AverageDamageInBattle_team1 << std::endl;
        os << "Average damage in Battle - team2 : " << matchmaking.AverageDamageInBattle_team2 << std::endl;
        os << "Average experience in Battle - team 1 : " << matchmaking.AverageExperienceInBattle_team1 << std::endl;
        os << "Average experience in Battle - team 2 : " << matchmaking.AverageExperienceInBattle_team2 << std::endl;
        os << "Max damage in Battle - team 1 : " << matchmaking.MaxDamageInBattle_team1 << std::endl;
        os << "Max damage in Battle - team 2 : " << matchmaking.MaxDamageInBattle_team2 << std::endl;
        os << "Max experience in Battle - team 1 : " << matchmaking.MaxExperienceInBattle_team1 << std::endl;
        os << "Max experience in Battle - team 1 : " << matchmaking.MaxExperienceInBattle_team2 << std::endl;
        os << "******************************************************************" << std::endl;

        return os;
    }
};

ScoreBoard score;
Crew c;

int main()
{
   /* c.setCommanderAge(69);
    std::cout << c.getCommanderAge();*/
    //std::cout << score.Pteam1.front();

    std::list<Platoon> pom;
    pom = score.Pteam2;

    // treba da ima 6 Tiger II , sto i ima; a kod prvog niza platoonova treba da ima 8. 
    // 6 = 2*(3), 2 tenka zbog praznog konstruktora je u jednom platoonu a imam 3 platoouna , 3 * 2

    std::list<Platoon> ::const_iterator ip = pom.begin();
    for (; ip != pom.end(); ip++) {
        std::cout << *ip << std::endl;
    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
