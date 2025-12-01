package BinaryTree;

public class tree {
    private class node {
        int number = 0;
        node right = null;
        node left = null;

    }

    private node root = null;
    private int size = 0;

    public void insert(int number) {
        if (size == 0) {

            root = new node();
            root.number = number;

            size++;
            System.out.println("Root added, size = " + size + "\n");

            return;
        }

        node current = root;

        while (true) {

            if (number > current.number) {

                if (current.right != null) {

                    current = current.right;
                    System.out.println("move Right");

                } else {

                    node new_node = new node();
                    new_node.number = number;
                    new_node.left = new_node.right = null;

                    current.right = new_node;
                    size++;

                    System.out.println("move Right");
                    System.out.println("New node created");
                    System.out.println("inserted successfully, size = " + size + "\n");

                    return;
                }

            } else if (number < current.number) {
                if (current.left != null) {

                    current = current.left;
                    System.out.println("move Left");

                } else {
                    node new_node = new node();
                    new_node.number = number;
                    new_node.left = new_node.right = null;

                    current.left = new_node;
                    size++;

                    System.out.println("move Left");
                    System.out.println("New node created");
                    System.out.println("inserted successfully, size = " + size + "\n");

                    return;
                }
            } else {
                System.out.println("Error");
                return;
            }

        }

    }

    public node search_recursive(int number) {
        if (size == 0) {

            System.out.println(" No Root yet\n");
            return null;
        }

        node current = root;

        while (current != null) {

            if (current.number == number) {
                System.out.println("\nNumber found");
                return current;
            }

            if (number > current.number) {
                System.out.println("move right");
                current = current.right;
            } else {
                System.out.println("Move left");
                current = current.left;
            }

        }

        System.out.println("\nNumber not found");
        return null;
    }

    private void preorder_traversel(node current) {

        if (current != null) {
            System.out.print(current.number + " ");
            preorder_traversel(current.left);
            preorder_traversel(current.right);
        }

    }

    public void print_preorder() {
        System.out.println("Pre order traversel");
        preorder_traversel(root);
        System.out.println();
    }

    private void inorder_traversal(node current) {
        if (current != null) {
            inorder_traversal(current.left);
            System.out.print(current.number + " ");
            inorder_traversal(current.right);
        }
    }

    public void print_inorder() {
        System.out.println("In order traversel");
        inorder_traversal(root);
        System.out.println();
    }

    private void postorder_traversal(node current) {
        if (current != null) {
            postorder_traversal(current.left);
            postorder_traversal(current.right);
            System.out.print(current.number + " ");
        }
    }

    public void print_postorder() {
        System.out.println("Post order traversel");
        postorder_traversal(root);
        System.out.println();
    }

    private String preorder_string = "";

    public void insert_for_delete(int number) {
        if (size == 0) {

            root = new node();
            root.number = number;

            size++;

            return;
        }

        node current = root;

        while (true) {

            if (number > current.number) {

                if (current.right != null) {
                    current = current.right;
                } else {

                    node new_node = new node();
                    new_node.number = number;
                    new_node.left = new_node.right = null;

                    current.right = new_node;
                    size++;
                    return;
                }

            } else if (number < current.number) {
                if (current.left != null) {
                    current = current.left;
                } else {
                    node new_node = new node();
                    new_node.number = number;
                    new_node.left = new_node.right = null;

                    current.left = new_node;
                    size++;
                    return;
                }
            }

        }

    }

    private void get_preorder_string(node current,int number_to_remove) {

        if (current != null) {
            if(current.number != number_to_remove)
                preorder_string += current.number + " ";
            get_preorder_string(current.left,number_to_remove);
            get_preorder_string(current.right,number_to_remove);
        }

    }

    private int[] get_preorder_int_arry(int number_to_remove) {

        get_preorder_string(root, number_to_remove);

        String[] items = preorder_string.trim().split("\\s+");
        
        int[] arr = new int[items.length];

        for (int i = 0; i < items.length; i++) {
            arr[i] = Integer.parseInt(items[i]);
        }
        return arr;
    }

    public void delete(int number_to_remove) {
        int[] items = get_preorder_int_arry(number_to_remove);
        
        System.out.println("\nNumber " + number_to_remove + " Removed\n");

        root = null;
        size = 0;

        for (int i : items) {
            insert_for_delete(i);
        }
    }

}