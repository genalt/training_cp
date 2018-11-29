import java.util.*;

class Book implements Comparable<Book> {
    public String author;
    public String title;
    public boolean available;


    Book(String inAuthor, String inTitle) {
        author = inAuthor;
        title = inTitle;
        available = true;
    }

    @Override
    public int compareTo(Book other) {

        if (author.compareTo(other.author) > 0)
            return 1;
        else if (author.compareTo(other.author) < 0)
            return -1;
        else {
            if (title.compareTo(other.title) > 0)
                return 1;
            else if (title.compareTo(other.title) < 0)
                return -1;
        }
        return 0;
    }
}


public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        ArrayList<Book> shelf = new ArrayList<>();
        ArrayList<Book> returned = new ArrayList<>();
        ArrayList<String> instructions = new ArrayList<>();
        String req = "";

        // FILL SHELVES
        while (true) {
            req = s.nextLine();
            if (req.compareTo("END") == 0)
                break;
            String[] barr = req.split("\" by ");
            shelf.add(new Book(barr[1].trim(), barr[0].trim() + "\""));

        }
        Collections.sort(shelf);

        //PROCESS REQUESTS
        while (true) {
            req = s.nextLine();
            if (req.compareTo("END") == 0)
                break;

            if (req.startsWith("BORROW")) {
                String title = req.substring(7);
                for (Book b : shelf) {
                    if (b.title.compareTo(title) == 0) {
                        b.available = false;
                        break;
                    }
                }
            }

            if (req.startsWith("RETURN")) {
                String title = req.substring(7);
                for (Book b : shelf) {
                    if (b.title.compareTo(title) == 0) {
                        returned.add(b);
                        b.available = true;
                        break;
                    }
                }
            }

            if (req.startsWith("SHELVE")) {
                Collections.sort(returned);
                for (Book r : returned) {
                    Book prev = null;
                    for (Book b : shelf) {
                        if (b.available && r.title.compareTo(b.title) != 0)
                            prev = b;

                        if (b.title.compareTo(r.title) == 0) { // found returned req place

                            if (prev != null)
                                instructions.add("Put " + r.title + " after " + prev.title);
                            else
                                instructions.add("Put " + r.title + " first");

                            break;
                        }
                    }
                }

                for (String i : instructions) {
                    System.out.println(i);
                }
                System.out.println("END");
                returned.clear();
                instructions.clear();
            }
        }
    }
}
