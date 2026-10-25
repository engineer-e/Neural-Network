import { Matrix } from "./matrix.js";
import { TransferFunction } from "./tranfer_function.js";


class RecurrentLayer {
    constructor({ p, w, b = 1, n, f, a }) {
        this.p = p
        this.w = w
        this.b = b
        this.n = n
        this.f = f
        this.a = a
    }

    forward({ f = TransferFunction.LOGSIG }) {
        //p = Rx1
        //w = SxR
        //b = Sx1
        //n = Sx1
        //a = Sx1
        this.a = new Matrix(this.p.row,this.p.column)
        this.a.ones()
       

       for(var t=0;t<2;t++){

        var wp = Matrix.mux(this.a, this.w)
        var temp_bias = new Matrix(wp.row, wp.column)
        temp_bias.scan(this.b, {})
        this.n = Matrix.add(wp, temp_bias)

        //console.log(this.n)

        this.f = new TransferFunction({ n: this.n, f: f })
        this.d = this.p.mul(Math.sin(t)) 
        this.a = this.d
        
       } 

       return this.a
        
    }
}

export { RecurrentLayer }

var input = new Matrix(5, 1)
input.m = [[1], [1], [0], [0],[1]]


var weight = new Matrix(1, 3)
weight.m = [[3,5,2]]


var weight2 = new Matrix(3, 2)
weight2.m = [[3,2],[4,5],[.5,2]]


var n1 = new RecurrentLayer({ p: input, w: weight, b: -1.5 })

var o1 = n1.forward({ f: TransferFunction.HARDLIMS})
console.log(o1)


// var n2 = new Layer({ p: o1, w: weight2, b: -1.5 })
// var o2 = n2.forward({ f: TransferFunction.TANSIG})


// console.log(o2)


//console.log(n.forward({ f: TransferFunction.HARDLIMS }))
//console.log(n.forward({ f: TransferFunction.PURELIN }))
//console.log(n.forward({ f: TransferFunction.SATLIN }))
//console.log(n.forward({ f: TransferFunction.SATLINS }))
//console.log(n.forward({ f: TransferFunction.LOGSIG }))
//console.log(n.forward({ f: TransferFunction.TANSIG }))
//console.log(n.forward({ f: TransferFunction.POSLIN }))
//console.log(n.forward({ f: TransferFunction.COMPET }))
