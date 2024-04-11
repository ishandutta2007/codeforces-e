namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;

    operation Solve(unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using ((q1, q2) = (Qubit(), Qubit())) {
            within {
                H(q1);
                CNOT(q1, q2);
            } apply {
                unitary(q2);
            }
            let res = ResultArrayAsInt([M(q2), M(q1)]);
            ResetAll([q1, q2]);
            return res >= 2 ? res ^^^ 1 | res;
        }
    }
}