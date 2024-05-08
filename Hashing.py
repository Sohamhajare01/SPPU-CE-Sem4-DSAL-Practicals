def hash_function(key, size):
    return key % size

def linear_probe(table, key, size):
    index = hash_function(key, size)
    while table[index] is not None:
        index = (index + 1) % size
    return index

def quadratic_probe(table, key, size):
    index = hash_function(key, size)
    attempt = 1
    while table[index] is not None:
        index = (index + attempt**2) % size
        attempt += 1
    return index

def insert_linear_probe(table, key, value, size):
    index = linear_probe(table, key, size)
    table[index] = (key, value)

def insert_quadratic_probe(table, key, value, size):
    index = quadratic_probe(table, key, size)
    table[index] = (key, value)

def search(table, key, size):
    index = hash_function(key, size)
    initial_index = index
    while table[index] is not None:
        if table[index][0] == key:
            return index
        index = (index + 1) % size
        if index == initial_index:
            break
    return None

def delete(table, key, size):
    index = search(table, key, size)
    if index is not None:
        table[index] = None
        print("Element deleted successfully.")
    else:
        print("Element not found.")

def display_table(table):
    print("\nHash Table:")
    for i, item in enumerate(table):
        if item is not None:
            print(f"Index {i}: {item}")
        else:
            print(f"Index {i}: Empty")

def main():
    size = int(input("Enter the size of the hash table: "))
    table = [None] * size
    while True:
        print("\n1. Insert")
        print("2. Delete")
        print("3. Search")
        print("4. Display")
        print("5. Exit")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            key = int(input("Enter key: "))
            value = input("Enter value: ")
            print("1. Linear Probing")
            print("2. Quadratic Probing")
            probe_choice = int(input("Enter your choice for probing: "))
            if probe_choice == 1:
                insert_linear_probe(table, key, value, size)
            elif probe_choice == 2:
                insert_quadratic_probe(table, key, value, size)
        elif choice == 2:
            key = int(input("Enter key to delete: "))
            delete(table, key, size)
        elif choice == 3:
            key = int(input("Enter key to search: "))
            index = search(table, key, size)
            if index is not None:
                print(f"Element found at index {index}.")
            else:
                print("Element not found.")
        elif choice == 4:
            display_table(table)
        elif choice == 5:
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please try again.")

main()