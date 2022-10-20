```
import java.util.*;

class Chemistry {

    static String[] elements = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl",
            "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr",
            "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs",
            "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W",
            "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np",
            "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg",
            "Cn", "Uut", "Uuq", "Uup", "Uuh", "Uus", "Uuo"};
    public static void main(String[] args) {


        Scanner myScanner = new Scanner(System.in);
        System.out.print("Enter a word: ");
        String inputWord = myScanner.next();
        String chemWord = spellWord(inputWord);

        System.out.println(chemWord);

        myScanner.close();
    }

    /**
     * @param word     - the word that we want to re-spell using abbreviations of elements in the periodic table
     * @param elements - an array that contains the abbreviations of elements in the periodic table
     * @return word re-spelled using abbreviations of elements in the periodic table
     * <p>
     * The spellWord function will take in two parameters, word and elements.
     * 1. The parameter 'word' represents the word that we want to re-spell using an abbreviation of the elements from
     * the periodic table.
     * 2. The parameter 'elements' represents possible element abbreviations that you can use to re-spell the word.
     * <p>
     * The function needs to return a String representing the word that you have re-spelled
     * using abbreviations of the elements in the periodic table.
     */
    static LinkedList<String> result = new LinkedList<>();
    static String[] warehouse = Arrays.stream(elements).map(String::toLowerCase).toArray(String[]::new);
    static Set<String> set = new HashSet<>(Arrays.asList(warehouse));
    static boolean isPresent = false;
    private static void subsequence(String str, int end) {

        if (end < 0) {
            // System.out.println(result);
            if (set.containsAll(result)) {
                isPresent = true;
                while (!result.isEmpty()) {
                    String deleted = result.removeLast();
                    System.out.print(deleted.substring(0,1).toUpperCase() + deleted.substring(1));
                }
            }
            return;
        }

        result.add(str.substring(end, end + 1));
        subsequence(str, end - 1);
        if (isPresent) return;
        result.removeLast();

        if (end >= 1) {
            result.add(str.substring(end - 1, end + 1));
            subsequence(str, end - 2);
            if (isPresent) return;
            result.removeLast();
        }

        if (end >= 2) {
            result.add(str.substring(end - 2, end + 1));
            subsequence(str, end - 3);
            if (isPresent) return;
            result.removeLast();
        }
    }
    public static String spellWord(String word) {
        subsequence(word.toLowerCase(), word.length() - 1);
        if (!isPresent) System.out.println("cannot spell word");
        return "";
    }


}
```