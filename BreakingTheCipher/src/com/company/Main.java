package com.company;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static int[] indexPrepositions = new int[9]; // хранит индексы комбинации предлогов
    public static String[] prepositions = {
            "на", "те", "но", "по",
            "нe", "он", "мы", "то",
            "из",
    }; // массив с предлогами
    public static ArrayList<Pair[]> prepositionsInText; // массив с предлогами из текста
    public static int keyLength; // длина ключа

    public static char[] alphabet = {
            'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з',
            'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р',
            'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ',
            'ь', 'ы', 'ъ', 'э', 'ю', 'я',
    }; // алфавит

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Введите текст: ");
        String originalText = sc.nextLine();

        System.out.print("Введите длину ключа: ");
        keyLength = sc.nextInt();

        // Получаем двойные предлоги в паре с их индексами
        prepositionsInText = getPrepositions(originalText);

        // ищем ключ
        String key = findKey(keyLength);

    }

    public static String findKey(int keyLength) {
        String key = "";

        // перебираем комбинации
        combinationsOfPrepositions(0,0);

        return key;
    }

    public static void combinationsOfPrepositions(int pos, int maxUsed) {
        // получаем массив с комбинацией предлогов
        if(pos == prepositions.length) {
            ArrayList<Pair[]> predictKeys = new ArrayList<>();
            for (int i = 0; i < prepositionsInText.toArray().length; i++) {
                // каждому предлогу из текста находим пару и вычисляем вероятный ключ
                Pair[] prep = {
                    new Pair(0, prepositions[i % prepositions.length].charAt(0)),
                        new Pair(0, prepositions[i % prepositions.length].charAt(1)),
                };
                predictKeys.add(getPredictKey(prepositionsInText.get(i), prep));
            }
            // проверяем, подходит ли ключ
            for (Pair[] p : predictKeys) {
                for (int i = 0; i < keyLength; i++) {
                    System.out.print(p[i].value);
                }
                System.out.println();
            }
            System.out.println();


        } else {
            for(int i = maxUsed; i < prepositions.length; i++) {
                indexPrepositions[pos] = i;
                combinationsOfPrepositions(pos + 1, i);
            }
        }
    }

    public static Pair[] getPredictKey(Pair[] prepositionInText, Pair[] prep) {
        // делаем массив с ключом и заполняем его временнымы символами
        Pair[] keyArray = new Pair[keyLength];
        for (int i = 0; i < keyLength; i++) {
            keyArray[i] = new Pair(i, '*');
        }

        // вписываем предпологаемую букву
        keyArray[(prepositionInText[0].key() - 1) % keyLength].value = alphabet[(new String(alphabet).indexOf(prepositionInText[0].value()) - new String(alphabet).indexOf(prep[0].value()) + 33) % 33];
        keyArray[(prepositionInText[1].key() - 1) % keyLength].value = alphabet[(new String(alphabet).indexOf(prepositionInText[1].value()) - new String(alphabet).indexOf(prep[1].value()) + 33) % 33];

        return keyArray;
    }

    static ArrayList<Pair[]> getPrepositions(String str) {
        // возвращает массив предлогов, где каждому символу предлога сопоставлен его индекс в тексте
        str = ' ' + str + ' ';
        ArrayList<Pair[]> prepositions = new ArrayList<>();

        for (int i = 1; i < str.length() - 2; i++) {
            // если находим двойной предлог, то добавляем его и идём дальше
            if (str.charAt(i - 1) == ' ' && str.charAt(i + 2) == ' ') {
                Pair[] tmpArray = {
                        new Pair(i, str.charAt(i)),
                        new Pair(i + 1, str.charAt(i + 1)),
                };
                prepositions.add(tmpArray);
                i++;
            }
        }

        return prepositions;
    }
}
