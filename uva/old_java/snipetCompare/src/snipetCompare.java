import java.util.Collections;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Comparator;

class MyDate implements Comparable<MyDate> {

    public int getDay() {
        return day;
    }

    public int getMonth() {
        return month;
    }

    public int getYear() {
        return year;
    }

    private int day;
    private int month;
    private int year;

    MyDate() {

    }

    MyDate(int inDay, int inMonth, int inYear) {
        this.day = inDay;
        this.month = inMonth;
        this.year = inYear;
    }

    @Override
    public int compareTo(MyDate other) {
        if(this.year > other.year)
            return -1;
        else if(this.year < other.year)
            return 1;

        // continue if years are the same
        if(this.month > other.month)
            return -1;
        else if(this.month < other.month)
            return 1;

        // continue if months are the same
        if(this.day > other.day)
            return -1;
        else if(this.day < other.day)
            return 1;

        return 0;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(day);
        sb.append('/');
        sb.append(month);
        sb.append('/');
        sb.append(year);

        return sb.toString();
    }

    public static class MonthComparator implements Comparator<MyDate> {
        @Override
        public int compare(MyDate date1, MyDate date2) {
            return date1.getMonth() - date2.getMonth();
        }
    }

    public static class YearComparator implements Comparator<MyDate> {
        @Override
        public int compare(MyDate date1, MyDate date2) {
            return date1.getYear() - date2.getYear();
        }
    }
}



public class snipetCompare {
    public static void main(String[] args) {

        MyDate one = new MyDate(15, 10, 1981);
        MyDate second = new MyDate(16, 9, 1987);
        MyDate third = new MyDate(16, 8, 1986);

        ArrayList<MyDate> mdl = new ArrayList<>();
        PriorityQueue<MyDate> pq = new PriorityQueue<>(10, new MyDate.YearComparator());

        mdl.add(one);
        mdl.add(second);
        mdl.add(third);

        if(one.compareTo(second) > 0) {

            System.out.println("one is older");

        }
        else if (one.compareTo(second) < 0) {
            System.out.println("one is younger");
        }
        else
            System.out.println("The same");


        Collections.sort(mdl, new MyDate.MonthComparator());

        for(MyDate cur: mdl)
            System.out.println(cur);


        pq.add(one);
        pq.add(second);
        pq.add(third);

        while(!pq.isEmpty()) {
            System.out.println(pq.remove());
        }

    }
}
