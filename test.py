
def main(): 
    with open("test123.txt") as f:
        s1 = {int(line, 16) for line in f if line.strip()}
    
    with open("predictions.txt") as f:
        s2 = {int(line, 16) for line in f if line.strip()}

    f = s1.intersection(s2)
    print(f"Accuracy: {len(f) / len(s1)}")

    
if __name__ == "__main__": 
    main()

