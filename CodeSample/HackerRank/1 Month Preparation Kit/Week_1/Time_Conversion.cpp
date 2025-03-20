string timeConversion(string s) {
    string hour = s.substr(0,2);
    string min = s.substr(3,2);
    string sec = s.substr(6,2);
    string period = s.substr(8,2);

    if (period == "AM") {
        if (hour == "12") {
            hour = "00";
        }
    } else if ((period == "PM") and (hour != "12")) {
        hour = to_string(stoi(hour) + 12);
        if (hour == "0") {
            hour += "0";
        }
    }
    
    return hour+":"+min+":"+sec;
}