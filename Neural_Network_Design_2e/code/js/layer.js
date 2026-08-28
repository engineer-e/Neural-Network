import { Matrix } from "./matrix.js";
import { TransferFunction } from "./tranfer_function.js";


class Layer {
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

export { Layer }

var input = new Matrix(2, 1)
input.m = [[-.012], [2]]


var weight = new Matrix(1, 3)
weight.m = [[3,5,2]]


var weight2 = new Matrix(3, 2)
weight2.m = [[3,2],[4,5],[.5,2]]


var n1 = new Layer({ p: input, w: weight, b: -1.5 })

var o1 = n1.forward({ f: TransferFunction.TANSIG})
console.log(o1)


var n2 = new Layer({ p: o1, w: weight2, b: -1.5 })
var o2 = n2.forward({ f: TransferFunction.TANSIG})


console.log(o2)


//console.log(n.forward({ f: TransferFunction.HARDLIMS }))
//console.log(n.forward({ f: TransferFunction.PURELIN }))
//console.log(n.forward({ f: TransferFunction.SATLIN }))
//console.log(n.forward({ f: TransferFunction.SATLINS }))
//console.log(n.forward({ f: TransferFunction.LOGSIG }))
//console.log(n.forward({ f: TransferFunction.TANSIG }))
//console.log(n.forward({ f: TransferFunction.POSLIN }))
//console.log(n.forward({ f: TransferFunction.COMPET }))
