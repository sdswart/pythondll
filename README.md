# PythonDll
A DLL wrapper for Python 3. programmed in C++ (Visual Studio) - intended for use in MT5 (MQL5)

The intended application of this project is to create a 64bit linker to python for use in metatrader 5 (mql5). 

Example import in mql5:

#import "[Path to PythonDll.dll"
   long CallPython(double &a[][11], int array_rows, int array_cols, string &FileName, string &FuncName, int &args[]);
#import

Example call in mql5:

void CallPython()
  {
   Print("Writing data to file...");
   double AllInputs[][11];    // 2D matrix of data to be passed to python (the Dll allows for up to 20 fields but you can use fewer)
   EnterDataIntoMatrix(AllInputs,NumRows); // Add data to the matrix using another function (EnterDataIntoMatrix) 
   int args[] = {1,1}; //Add any additional arguments that will be passed to python
   string FileString = "PythonCode"; //Name of the python file E.g. PythonCode.py
   string FuncString = "WriteData"; //Name ofthe function in the python file. Example here is for: def WriteData(a, args):
   Print("Result = " ,CallPython(AllInputs,NumRows,NumCols,FileString,FuncString,args)); //Call the python function and retrieve a long result (NumCols=11 in this example)
   
   return(INIT_SUCCEEDED);
  }

Example python function:
def WriteData(matrix, args):
    DataFileName = 'AllData.csv'
    file = open(DataFileName, 'w')
    writer = csv.writer(file,lineterminator = '\n')
    for row in matrix:
        writer.writerow(row)
    
    file.close()
    return 1;