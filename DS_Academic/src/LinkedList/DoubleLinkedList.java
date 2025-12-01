package LinkedList;

public class DoubleLinkedList<T> {

    private class node {
        T value;
        node next = null;
        node prev = null;

        node(T value) {
            this.value = value;
        }
    }

    private node head = null;
    private int size = 0;

    public void inset_at_beginning(T value) {
        node new_node = new node(value);

        if (head == null) {
            head = new_node;
            size++;
            return;
        }

        new_node.next = head;
        new_node.prev = null;
        head.prev = new_node;
        head = new_node;
        size++;
    }

    public void insert_at_last(T value) {
        node new_node = new node(value);

        if (head == null) {
            head = new_node;
            size++;
            return;
        }

        node current = head;

        while (current.next != null) {
            current = current.next;
        }

        current.next = new_node;
        new_node.prev = current;
        size++;
    }

    public void delete(T value) {

        if (size == 0) {
            System.out.println("No item yet");
            return;
        }
        
        if (size == 1) {
            if (head.value == value) {

                head = null;
                size--;
                return;

            } else {
                System.out.println("Item was not found");
                return;
            }
        }

        node current = head;

        while (current != null) {

            if (current.value.equals(value)) {

                if (current.prev == null) { //case we deleted the head 

                    current.next.prev = null;
                    head = current.next;
                    current = null;
                    size--;
                } else if (current.next == null) { //case we deleted the tail 

                    current.prev.next = null;
                    current = null;
                    size--;

                } else {

                    current.prev.next = current.next;
                    current.next.prev = current.prev;
                    current = null;
                    size--;

                }
                return;
            }
            current = current.next;
        }
        System.out.println("Item was not found");
        
    }

    public void traversal() {
        node new_node = head;
        System.out.print("Null ");

        while (new_node != null) {
            System.out.print("<-- " + new_node.value + " -->");
            new_node = new_node.next;
        }
        System.out.println(" Null");
        System.out.println();
    }

}