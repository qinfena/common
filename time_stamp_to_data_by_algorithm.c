#include <stdio.h>
#include <sys/time.h>

static const int DAYMS = 3600 * 24;
static const int FOURYEARS = (365 + 365 + 365 + 366);
static const int MON1[12] = {31, 30, 31, 28, 31, 30, 31, 31, 30, 31, 30, 31};
static const int MON2[12] = {31, 30, 31, 29, 31, 30, 31, 31, 30, 31, 30, 31}; //

void GetMonthAndDay(int nDays, int *nMonth, int *nDay, int IsLeapYear);
void GetHourMinSec(int nSecond);

int
main() {
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);

	int year,mom, day, hour, minute, second;
	int nYear4, nRemain, nDesYear, nDesMon, nDesDay;
	long sum;
	int bLeapYear = 0;

	printf("tv_sec:%d\n", tv.tv_sec);
	day = tv.tv_sec / DAYMS;
	nYear4 = day / FOURYEARS;
	nRemain = day % FOURYEARS;
	nDesYear = 1970 + nYear4 * 4;
	if (nRemain < 365) {

	}else if (nRemain < (365 + 365 )) {
		nDesYear += 1;
		nRemain  -= 365;
	}else if (nRemain < (365 + 365 + 365)) {
		nDesYear += 2;
		nRemain  -= (365 + 365);
	}else{
		nDesYear += 3;
		nRemain  -= (365 + 365 + 365);
		bLeapYear = 1;
	}
	GetMonthAndDay(nRemain, &nDesMon, &nDesDay, bLeapYear);

	//printf("day = %d nDesYear = %d nremain = %d \n", day, nDesYear, nRemain);
	printf("%d-%d-%d\n", nDesYear, nDesMon, nDesDay);
	GetHourMinSec(tv.tv_sec % (3600 * 24));

	return 0;
}

void GetMonthAndDay(int nDays, int *nMonth, int *nDay,int IsLeapYear){
	int * pMonth = (IsLeapYear)?MON2:MON1;
	int i;
	for (i = 0; i < 12; i++) {
		int nTemp;
		nTemp = nDays - pMonth[i];
		if (nTemp <= 0) {
			*nMonth = 1 + i;
			if (nTemp == 0) {
				*nDay = pMonth[i];
			}else{
				*nDay = nDays;
			}
			break;
		}
		nDays = nTemp;
	}
}
void GetHourMinSec(int nSecond) {
	int hour = nSecond / 3600 + 8;
	int minute = (nSecond % 3600) / 60;
	int second = (nSecond % 3600) % 60;
	printf("%d:%d:%d\n", hour, minute, second);
}

