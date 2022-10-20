```java
int getSuitPriority(String suitString) {
    if(suitString.equals("spades")) return 4;
    if(suitString.equals("diamond")) return 3;
    if(suitString.equals("hearts")) return 2;
    return 1;
}
public void game(Cards c1, Cards c2) {
    if(c1.value == c2.value) {
        if(c1.getSuitPriority(c1.suit) > c1.getSuitPriority(c1.suit)) {
            points1++;
        } else points2++;
    } else if(c1.value > c2.value) points1++;
    else points2++;

    System.out.println("points of player 1 :" + " " + points1);
    System.out.println("points of player 2 :" + " " + points2);
}

```