//char *strcpy( char *dest, const char *src );

class Student
{
    private:
        char name[50];
        int b_day;
        int b_month;
        int b_year;
        char phone[15];
        char town[50];
        char country[50];
        char educ_name[50];
        char educ_town[50];
        char educ_country[50];
        char group[50];
    public:
        Student();

        void setName(const char* _name);
        char* getName();
        void setBithDate(int day, int month, int year);
        void setPhone(const char* _phone);
        char* getPhone();
        void setTown(const char* _town);
        char* getTown();
        void setCountry(const char* _country);
        char* getCountry();
        void setEducName(const char* _educ_name);
        char* getEducName();
        void setEducTown(const char* _educ_town);
        char* getEducTown();
        void setEducCountry(const char* _educ_country);
        char* getEducCountry();
        void setGroup(const char* _group);
        char* getGroup();
        void show();
};