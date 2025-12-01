package LinkedList;

public class SingleLinkedList<T> {

    private class node {
        T value;
        node next = null;
    }

    node head = null;
    node tail = null;
    int length = 0;

    public boolean is_empty() {
        return (length == 0);
    }

    public void insert_at_first(T value) {
        node new_node = new node();
        new_node.value = value;

        if (is_empty()) {
            head = tail = new_node;
            new_node.next = null;
        } else {
            new_node.next = head;
            head = new_node;
        }
        length++;
    }

    public void insert_at_last(T value) {
        node new_node = new node();
        new_node.value = value;
        new_node.next = null;

        if (is_empty()) {
            head = tail = new_node;
        } else {
            tail.next = new_node;
            tail = new_node;
        }
        length++;
    }

    public void traverse() {
        node current = head;
        while (current.next != null) {
            System.out.print(current.value + " ");
            current = current.next;
        }

        System.out.println(current.value);
    }

    public void insert_at_position(int pos, T value) {
        node new_node = new node();
        new_node.value = value;

        if (pos == 0)
            insert_at_first(value);
        else if (pos == length)
            insert_at_last(value);
        else if (pos < 0 || pos > length)
            System.out.println("out of range");
        else {
            node current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current.next;
            }
            new_node.next = current.next;
            current.next = new_node;
            length++;
        }
    }

    public void delete_value(T value) {
        if (is_empty())
            return;

        // Case 1: delete head
        if (head.value.equals(value)) {
            head = head.next;
            length--;
            if (head == null) { // list became empty
                tail = null;
            }
            return;
        }

        // Case 2: delete in the middle or tail
        node current = head;
        while (current.next != null) {
            if (current.next.value.equals(value)) {
                // If deleting tail
                if (current.next == tail) {
                    tail = current;
                }
                current.next = current.next.next;
                length--;
                return;
            }
            current = current.next;
        }
    }

}
