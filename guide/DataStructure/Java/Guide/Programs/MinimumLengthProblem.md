Hi Vaidya, Thanks for reaching out to us.

You need to check whether str2 contains all the characters of string1 or not. if it contains all the characters of string 1 then return the minimum length of string2 which contains all the letters of string1 else return -1.

 
Method 3 is efficient among the other 2 methods because of fewer traversals and calculations.
 
Method 1:

Convert both strings into a list of characters and use the containsAll method of the list interface.

```java
public static int check(String p, String s) {
    //write your code here
    List<Character> list1 = new ArrayList<>();
    for (char ch : p.toCharArray()) {
        list1.add(ch);
    }

    List<Character> list2 = new ArrayList<>();
    for (char ch : s.toCharArray()) {
        list2.add(ch);
    }

    System.out.println(list1);
    System.out.println(list2);
    return list2.containsAll(list1) ? list1.size() : -1;

}
 


```

Method 2:

Calculating the frequency of every character of both the strings and then comparing their frequency accordingly.

```java

public static int check(String p, String s) {
    Map<Character, Integer> map1 = new HashMap<>();
    for (int i = 0; i < p.length(); i++) {
        int count = map1.getOrDefault(p.charAt(i), 0);
        map1.put(p.charAt(i), count + 1);
    }

    Map<Character, Integer> map2 = new HashMap<>();
    for (int i = 0; i < s.length(); i++) {
        int count = map2.getOrDefault(s.charAt(i), 0);
        map2.put(s.charAt(i), count + 1);
    }
    
    for (Map.Entry<Character, Integer> entry : map1.entrySet()) {

        if (map2.get(entry.getKey()) == null) return -1;

        // key is present now
        // checking for frequency of character
        if (map2.get(entry.getKey()) <= entry.getValue()) return -1;
    }
    return p.length();
}

```
 

Method 3: Using a sliding window and substring
```java
public static int check(String p, String s) {
    //write your code here

    if (s.length() < p.length()) return -1;
    int[] pCount = new int[256];
    int[] sCount = new int[256];

    for (int i = 0; i < p.length(); i++) {
        pCount[(int) p.charAt(i)]++;
        sCount[(int) s.charAt(i)]++;
    }

    int i = 0;
    int j = p.length();

    int min = Integer.MAX_VALUE;

    String res = null;

    while (j < s.length()) {
        if (contains(sCount, pCount)) {
            if ((j - i) < min) {
                min = j - i;
                res = s.substring(i, j);
                if (min == p.length()) break;
                sCount[(int) s.charAt(i)]--;
                i++;
            }
        } else {
            sCount[(int) s.charAt(j)]++;
            j++;
        }
    }
    return res.length();

}

```

----------
