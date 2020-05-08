int x;

int pow(int base, int power)
begin

    int i;
    int returnVal;

    i = 0;
    returnVal = 1;

    if (power <= 0)
    then begin
        return 1;
    end
    else
    begin

        while (i < power)
        do begin
            returnVal = returnVal * base;
            i = i + 1;
        end

    end

    return returnVal;

end


int powRecursive(int reBase, int powerRaised)
begin
    if (powerRaised != 0)
    then begin
        return (reBase * powRecursive(reBase, powerRaised - 1));
    end
    else
    begin
        return 1;
    end
end


void main(void)
begin

    int A[10];
    int i;
    int powTest;
    i = 0;
    x = 5;

    write "i is: ";
    write i; write "\n";

    write "x global is: "; 
    write x; write "\n";

    begin
        int i;
        i = 8888;
        write "Local block statement. Local i is: ";
        write i; write "\n";
    end

    write "Outside of block statement, i is back to : ";
    write i; write "\n\n";

    write "conditional test: \n";
    if (x) 
    then begin
        write "x is not 0. Positive statement \n";
    end
    else
    begin 
        write "x is 0. Negative statement\n";
    end
    write "end of conditional test\n\n";

    write "iteration test increment x while x <= 10\n";
    while x <= 10
    do begin
        write x; write "\n";
        x = x + 1;
    end
    write "Done with x <= 10 loop\n\n";

    write "iteration read test. read x while x < 100\n";
    x = 0;
    while x < 100 do read x;

    write "end iteration read test\n\n";

    write "Not operation test: \n";
    write "Not true is ";
    write not true; write "\n";
    write "Not false is "; 
    write not false; write "\n\n\n";


    write "array assignment test: \n";
    while i < 10
    do begin
        A[i] = i;
        write A[i]; write "\n";
        i = i + 1;
    end
    write "end of array assignment test\n\n\n";
    

    i = 12;
    x = A[2];

    write "i is now: ";
    write i; write "\n";

    write " x is now: ";
    write x; write "\n";

    write "Function call tests. pow() is calculates powers, powRecursive() does the same thing recursively.\n";
    
    powTest = pow(i, x);
    write "Assigned powTest with pow(i, x). powTest is now: ";
    write powTest; write "\n\n";

    write "A[pow(2,2)] (same thing as A[4]) is: ";
    write A[pow(2,2)]; write "\n\n";

    powTest = pow(i, A[pow(2, 2)]);
    write "assigned powTest with pow(i, A[pow(2,2)]). powTest is now: ";
    write powTest; write "\n\n";

    write "Recursive power test: \n";
    write "powRecursive(2, 3) is: "; write powRecursive(2, 3);
end