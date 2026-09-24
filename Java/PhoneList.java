// File: PhoneList.java

public class PhoneList
{
    public static void main (String[] args)
    {
        Contact[] friends = new Contact[8];
        friends[0] = new Contact ("John", "Smith", "610-555-7384");
        friends[1] = new Contact ("Sarah", "Barnes", "215-555-3827");
        friends[2] = new Contact ("Mark", "Riley", "733-555-2969");
        friends[3] = new Contact ("Laura", "Getz", "663-555-3984");
        friends[4] = new Contact ("Larry", "Smith", "464-555-3489");
        friends[5] = new Contact ("Frank", "Phelps", "322-555-2284");
        friends[6] = new Contact ("Mario", "Guzman", "804-555-9066");
        friends[7] = new Contact ("Marsha", "Grant", "243-555-2837");
        
        Sorting.selectionSort(friends);
        
        for (int i = 0; i < friends.length; i++)
            System.out.println (friends[i]);
    }
}

class Contact implements Comparable
{
    private String firstName, lastName, phone;

    public Contact (String first, String last, String telephone)
    {
        firstName = first;
        lastName = last;
        phone = telephone;
    }

    public String toString ()
    {
        return lastName + ", " + firstName + "\t" + phone;
    }

    public boolean equals (Object other)
    {
        return (lastName.equals(((Contact)other).getLastName())
                &&
                firstName.equals(((Contact)other).getFirstName()));
    }

    public int compareTo (Object other)
    {
        int result;
        String otherFirst = ((Contact)other).getFirstName();
        String otherLast = ((Contact)other).getLastName();
        
        if (lastName.equals(otherLast))
            result = firstName.compareTo(otherFirst);
        else
            result = lastName.compareTo(otherLast);
            
        return result;
    }

    public String getFirstName ()
    {
        return firstName;
    }

    public String getLastName ()
    {
        return lastName;
    }
}

class Sorting
{
    public static void selectionSort (Comparable[] list)
    {
        int min;
        Comparable temp;
        for (int index = 0; index < list.length-1; index++)
        {
            min = index;
            for (int scan = index+1; scan < list.length; scan++)
                if (list[scan].compareTo(list[min]) < 0)
                    min = scan;
                    
            // Swap the values
            temp = list[min];
            list[min] = list[index];
            list[index] = temp;
        }
    }

    public static void insertionSort (Comparable[] list)
    {
        for (int index = 1; index < list.length; index++)
        {
            Comparable key = list[index];
            int position = index;
            
            // Shift larger values to the right
            while (position > 0 && key.compareTo(list[position-1]) < 0)
            {
                list[position] = list[position-1];
                position--;
            }
            list[position] = key;
        }
    }
}

class Searching
{
    public static Comparable linearSearch (Comparable[] list,
                                           Comparable target)
    {
        int index = 0;
        boolean found = false;
        while (!found && index < list.length)
        {
            if (list[index].equals(target))
                found = true;
            else
                index++;
        }

        if (found)
            return list[index];
        else
            return null;
    }

    public static Comparable binarySearch (Comparable[] list, Comparable target)
    {
        int min=0, max=list.length, mid=0;
        boolean found = false;
        
        while (!found && min <= max)
        {
            mid = (min+max) / 2;
            if (list[mid].equals(target))
                found = true;
            else
                if (target.compareTo(list[mid]) < 0)
                    max = mid-1;
                else
                    min = mid+1;
        }
        
        if (found)
            return list[mid];
        else
            return null;
    }
}