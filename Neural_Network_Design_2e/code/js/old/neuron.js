import { Matrix } from "./matrix.js"
import { TransferFunction } from "./tranfer_function.js"

class Neuron {
    constructor({ p, w, b = 1, n, f, a }) {
        this.p = p 
        this.w = w 
        this.b = b 
        this.n = n 
        this.f = f
        this.a = a  
    }

    forward({f=TransferFunction.LOGSIG}){
        //p = Rx1
        //w = SxR
        //b = Sx1
        //n = Sx1
        //a = Sx1

        var wp = Matrix.mux(this.p, this.w)
        var temp_bias = new Matrix(wp.row, wp.column)
        temp_bias.scan(this.b, {})
        this.n = Matrix.add(wp, temp_bias)

        console.log(this.n)

        this.f = new TransferFunction({ n: this.n, f: f })
        this.a = this.n
        return this.a
    }
}


export {Neuron}


// var input = new Matrix(1,1)
// input.m = [[2]]

// var weight = new Matrix(1,1)
// weight.m = [[3]]


// var n = new Neuron({p:input, w:weight, b:-1.5})
// console.log(n.forward({f:TransferFunction.HARDLIM}))