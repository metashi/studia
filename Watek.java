public class Watek extends Thread
{
    Obraz obraz;
    int searchedChar;
    public Watek(int i, Obraz obraz)
    {
        this.obraz = obraz;
        this.searchedChar = i;
    }
    public void run() {
        obraz.calculate_histogram_for_char(searchedChar);
        obraz.print_histogram_for_char(searchedChar);
    }
}
