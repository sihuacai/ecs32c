#ifndef DATE_H
#define DATE_H

/**
 * Some hints that may help as you implement the functions below:
 * 
 * 1. Do not return a pointer to any non-dynamically allocated memory.
 *
 * 2. You do need to be aware of leap years, not just when implementing
 *    nextDay() but also in at least one of the other functions. You'll
 *    have to figure out which ones. We will go by the Gregorian
 *    calendar rules when determining what constitutes a leap year.
 *    You should probably make a helper function to determine if a
 *    given year is a leap year.
 *    I found the following two links helpful in determining when a given
 *    year is a leap year:
 *
 *    - https://en.wikipedia.org/wiki/Leap_year#Algorithm
 *    - https://www.timeanddate.com/date/leapyear.html
 *
 * 3. I created an array containing the maximum number of days of each month
 *    (ignoring leap years). This array would have the values 31, 28, 31, and
 *    so on.
 */

struct Date;

/**
 * If given parameters are valid, returns new instance of struct Date
 * based on the given arguments.
 * (It is the responsibility of the caller to deallocate this instance.)
 * Otherwise, returns null pointer.
 *
 * Months are indicated by their three-letter abbreviations, i.e.
 * Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec.
 *
 * Nonpositive years are rejected.
 * You should be able to determine all of the conditions that could
 * constitute invalid dates.
 */
struct Date* createDate(const char* month, int day, int year);

/**
 * Deallocates any memory associated with the given struct Date
 * instance. If you don't dynamically allocate memory in createDate(),
 * then you shouldn't have to deallocate any memory (or do anything)
 * in this function except for free()-ing the argument d itself.
 *
 * Returns 0 if given a null pointer. Returns 1 otherwise.
 */
int destroyDate(struct Date* d);

/**
 * Returns copy of the month associated with the given date,
 * or NULL if given a null pointer.
 * The caller is responsible for deallocating the copy.
 */
char* getMonth(const struct Date* date);

/**
 * Returns 0 if given a null pointer, or else returns the day associated
 * with the given date.
 */
int getDay(const struct Date* date);

/**
 * Returns 0 if given a null pointer,
 * or else returns the year associated with the given date.
 */
int getYear(const struct Date* date);

/**
 * Updates the month member of the given struct Date instance.
 *
 * Returns 0 if given any null pointers or if given an invalid month,
 * i.e. if given a month that would invalidate the date.
 * (Note: The update should NOT be performed in this case.)
 *
 * Returns 1 if update is successful/performed.
 */
int setMonth(struct Date* date, const char* month);

/**
 * Updates the day member of the given struct Date instance.
 *
 * Returns 0 if given a null pointer or if given an invalid day.
 * (Note: The update should NOT be performed in this case.)
 *
 * Returns 1 if update is successful/performed.
 */
int setDay(struct Date* date, int day);

/**
 * Updates the year member of the given struct Year instance.
 *
 * Returns 0 if given a null pointer or if given an invalid year,
 * i.e. if given a year that would invalidate the date.
 * Nonpositive years are rejected.
 * (Note: The update should NOT be performed in this case.)
 *
 * Returns 1 if update is successful/performed.
 */
int setYear(struct Date* date, int year);

/**
 * Determines which of two given dates comes first.
 *
 * Returns -2 if either argument is a null pointer.
 * Returns -1 if d1 occurs before d2.
 * Returns 0 if the dates are equal.
 * Returns 1 otherwise (i.e. if d1 occurs after d2).
 */
int compareDay(const struct Date* d1, const struct Date* d2);

/**
 * Updates the given struct Date instance so that it now refers to
 * the next day.
 *
 * Returns 0 if given a null pointer.
 * Returns 1 otherwise.
 */
int nextDay(struct Date* date);

#endif // DATE_H

