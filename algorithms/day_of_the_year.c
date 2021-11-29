
bool IsLeapYear(int year) {
    bool div_by_4   = year % 4 == 0;
    bool div_by_100 = year % 100 == 0;
    bool div_by_400 = year % 400 == 0;
    bool is_leap_year = false;
    
    if(div_by_4   &&
       div_by_100 &&
       div_by_400) 
    {
        is_leap_year = true;    
    }
    else if(div_by_4 && !div_by_100) 
    {
        is_leap_year = true;
    }
    
    return is_leap_year;
}

int dayOfYear(char * date){
    int num_days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // get year as int
    char year_string[5];
    year_string[4] = '\0';
    memcpy(year_string, date, 4);
    int year = (int)strtol(year_string, NULL, 10);
    
    // get month as int
    char month_string[3];
    month_string[2] = '\0';
    memcpy(month_string, date + 5, 2);
    int month = (int)strtol(month_string, NULL, 10);
    
    // get day as int
    char day_string[3];
    day_string[2] = '\0';
    memcpy(day_string, date + 8, 2);
    int day = (int)strtol(day_string, NULL, 10);
    
    if(IsLeapYear(year)) {
        num_days_in_month[1] += 1;
    }
    int result = 0;
    for(int i = 1; i < month; ++i) {
        result += num_days_in_month[i - 1];
    }
    result += day;
    
    return result;
}
