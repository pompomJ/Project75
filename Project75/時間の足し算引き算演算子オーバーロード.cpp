#include <iostream>
using namespace std;

class SimpleTime {
public:
	SimpleTime() {
		hour = 0;
		minute = 0;
	}
	SimpleTime(int h, int m) {
		hour = h;
		minute = m;
	}
	void SetTime(int h, int m) {
		hour = h;
		minute = m;
	}
	void GetText(char * str) {
		sprintf(str, "%dŽžŠÔ%d•ª", hour, minute);
	}
	SimpleTime operator+(const SimpleTime &st);
	SimpleTime & operator+=(const SimpleTime &st);
	SimpleTime operator-(const SimpleTime &st);
	SimpleTime & operator-=(const SimpleTime &st);

	int hour;
	int minute;
};

SimpleTime SimpleTime::operator+(const SimpleTime &st)
{
	int hour_buf, minute_buf, total;
	total = (hour * 60 + minute) + (st.hour * 60 + st.minute);
	hour_buf = total / 60;
	minute_buf = total % 60;

	return SimpleTime(hour_buf, minute_buf);
}

SimpleTime & SimpleTime::operator+=(const SimpleTime &st)
{
	int total;
	total = (hour * 60 + minute) + (st.hour * 60 + st.minute);
	hour = total / 60;
	minute = total % 60;
	return *this;
}

SimpleTime SimpleTime::operator-(const SimpleTime &st)
{
	int hour_buf, minute_buf, total;
	total = (hour * 60 + minute) - (st.hour * 60 + st.minute);
	hour_buf = total / 60;
	minute_buf = total % 60;

	return SimpleTime(hour_buf, minute_buf);
}

SimpleTime & SimpleTime::operator-=(const SimpleTime &st)
{
	int total;
	total = (hour * 60 + minute) - (st.hour * 60 + st.minute);
	hour = total / 60;
	minute = total % 60;
	return *this;
}

int main()
{
	SimpleTime st, st1(5, 30), st2(2, 50), st3(1, 40);
	char buf[20];

	st = st1 + st2 - st3;
	st.GetText(buf);
	cout << "st1+st2-st3 " << buf << endl;

	st = st1;
	st += st2;
	st.GetText(buf);
	cout << "st1+st2 " << buf << endl;

	(st = st1) -= st2;
	st.GetText(buf);
	cout << "(st=st1)-=st2 " << buf << endl;
	return 0;
}