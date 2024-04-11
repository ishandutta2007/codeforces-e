namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            mutable len = Length(qs);
            H(qs[0]);
            for(i in 1..(len-1)){
              CNOT(qs[0], qs[i]);
            }
        }
    }
}