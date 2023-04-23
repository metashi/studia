import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Main {
    public static void main(String[] args) {

        Class classInstance = new Class("Group A", 20);

        classInstance.addStudent(new Student("Ewa", "Mazurek", 2001, 10, StudentCondition.CHORY, 123456789));
        classInstance.addStudent(new Student("Katarzyna", "Kwiat", 1999, 12, StudentCondition.ODRABIAJACY, 835934345));
        classInstance.addStudent(new Student("Tomasz", "Kowalski", 2001, 10, StudentCondition.CHORY, 123456789));

        new ClassInterface(classInstance);
        /*student2.print();

        //add to class
        System.out.println("Dodawanie do klasy\n");
        List studentArrayList = new ArrayList<Student>();
        studentArrayList.add(student1);
        studentArrayList.add(student2);
        Class classList = new Class("Klasa I", 3);
        classList.addStudent(student1);
        classList.addStudent(student2);

        //compare
        if(student2.compareTo(student1)) System.out.printf("Studenci mają takie samo nazwisko\n");
        else System.out.printf("Studenci nie mają takiego samego nazwiska\n");


        //points
        System.out.println("Dodaj punkty\n");
        classList.addPoints(student1, 5);

        //remove points
        classList.removePoints(student2, 3);

        //condition
        System.out.println("W jaki stanie jest student\n");
        classList.changeCondition(student2, StudentCondition.CHORY);

        //search
        System.out.println("Wyszukaj nazwisko:\n");
        Student search = classList.search("Kowalski");

        //serachPartial
        System.out.println("Wyszukaj fraze\n");
        List<String> searchPartial = classList.searchPartial("Kowa");

        //count
        System.out.println("Ilosc osob o danym stanie:\n");
        System.out.println("Ilość studentów o podanym stanie chorym: \n" + StudentCondition.CHORY.toString() + " " + classList.countByCondition(StudentCondition.CHORY));
        System.out.println("Ilość studentów o podanym stanie odrabiajacym: \n" + StudentCondition.ODRABIAJACY.toString() + " " + classList.countByCondition(StudentCondition.ODRABIAJACY));
        System.out.println("Ilość studentów o podanym stanie nieobecny: \n" + StudentCondition.NIEOBECNY.toString() + " " + classList.countByCondition(StudentCondition.NIEOBECNY));
        //summary
        System.out.println("Podsumowanie:\n");
        classList.summary();
        //sortByPoint
        System.out.println("Sortowanie po punktach\n");
        classList.sortByPoints();
        classList.summary();
        //max
        System.out.println("Max\n");
        classList.max();

        //add container
        System.out.println("Dodaj kontener\n");
        ClassContainer groupsContainer = new ClassContainer();
        groupsContainer.addClass("Klasa II", 5);
        ClassContainer groups3Container = new ClassContainer();
        groupsContainer.addClass("Klasa III", 6);
        //remove container
        System.out.println("Usun kontener\n");
        groupsContainer.removeClass("klasa III");
        //find empty
        System.out.println("Znajdz pusta grupe\n");
        ClassContainer groupsSecondContainer = new ClassContainer();
        groupsSecondContainer.addClass("Klasa II", 2);
        List emptyGroups = groupsSecondContainer.findEmpty();
        groupsSecondContainer.summary();*/

    }
}