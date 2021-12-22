package com.company;

public class Pair {
    public Integer key;
    public Character value;

    public Pair(Integer aKey, Character aValue)
    {
        key   = aKey;
        value = aValue;
    }

    public Integer key()   { return key; }
    public Character value() { return value; }
}
