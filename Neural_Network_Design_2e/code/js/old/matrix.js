class Matrix {

    constructor(row, column) {
        this.row = row
        this.column = column
        this.m = []
        this.scan(0.0, {})

    }

    scan(value, { diagonal = false, seq = false, index = 0, order = true }) {
        this.m = []
        //console.log(this.row, ",", this.column)
        for (var i = 0; i < this.row; i++) {
            var v = []
            for (var j = 0; j < this.column; j++) {
                v.push(diagonal ? ((i == j) ? seq ? index++ : value : 0.0) : seq ? index++ : value)
            }
            this.m.push(v)
        }

    }

    zeros() {
        this.scan(0.0, {})
    }
    ones() {
        this.scan(1.0, {})
    }

    identity() {
        this.scan(1.0, { diagonal: true })
    }

    transform() {
        var temp = new Matrix(this.column, this.row)

        for (var i = 0; i < this.row; i++) {
            for (var j = 0; j < this.column; j++) {
                temp.m[j][i] = this.m[i][j]
            }
        }

        this.m = temp.m;
    }

    static dot(a, b) {
        return this.matx({ u: a, v: b, o: '.' })
    }

    static add(a, b) {
        return this.matx({ u: a, v: b, o: '+' })

    }

    add(v) {
        var temp = new Matrix(this.row, this.column)
        temp.scan(v, {})
        return Matrix.add(this, temp)
    }

    sub(v) {
        var temp = new Matrix(this.row, this.column)
        temp.scan(v, {})
        return Matrix.sub(this, temp)
    }

    mul(v) {
        var temp = new Matrix(this.row, this.column)
        temp.scan(v, {})
        return Matrix.mul(this, temp)
    }

    div(v) {
        var temp = new Matrix(this.row, this.column)
        temp.scan(v, {})
        return Matrix.div(this, temp)
    }

    mod(v) {
        var temp = new Matrix(this.row, this.column)
        temp.scan(v, {})
        return Matrix.mod(this, temp)
    }

    static sub(a, b) {
        return this.matx({ u: a, v: b, o: '-' })

    }

    static mul(a, b) {
        return this.matx({ u: a, v: b, o: '*' })

    }
    
    static mux(a,b){
        return this.matx({ u: a, v: b, o: '@' })
    }

    static div(a, b) {
        return this.matx({ u: a, v: b, o: '/' })

    }

    static mod(a, b) {
        return this.matx({ u: a, v: b, o: '%' })

    }


    static matx({ u, v, o = '' }) {


        var ri = u.m.length, rj = u.m[0].length

        var si = null, sj = null;
        var d1 = null, d2 = null, d3 = null, d4 = null,d5=null,d6=null;


        if (v != null) {
            si = v.m.length, sj = v.m[0].length
            d1 = ri == sj
            d2 = rj == si
            d3 = ri == si
            d4 = rj == sj

            d5 = d1 == d2
            d6 = (ri == si) && (rj == sj)
            

            
        }


        //console.log(u,",", v)



        switch (o) {
            case '.': {
                var output = 0.0
                if (d6) {
                    for (var i = 0; i < ri; i++) {
                        for (var j = 0; j < rj; j++) {
                            output += u.m[i][j] * v.m[i][j]
                        }
                    }

                    var temp = new Matrix(1, 1)
                    temp.m[0][0] = output
                    return temp
                }
            } break;

            case '+': {
                if (d6) {
                    var temp = new Matrix(ri, rj)
                    for (var i = 0; i < ri; i++) {
                        for (var j = 0; j < rj; j++) {
                            temp.m[i][j] = u.m[i][j] + v.m[i][j]

                        }
                    }
                    return temp
                }
            } break;
            case '-': {
                if (d6) {
                    var temp = new Matrix(ri, rj)
                    for (var i = 0; i < ri; i++) {
                        for (var j = 0; j < rj; j++) {
                            temp.m[i][j] = u.m[i][j] - v.m[i][j]

                        }
                    }
                    return temp
                }
            } break;

            case '*': {
                if (d6) {
                    var temp = new Matrix(ri, rj)
                    for (var i = 0; i < ri; i++) {
                        for (var j = 0; j < rj; j++) {
                            temp.m[i][j] = u.m[i][j] * v.m[i][j]

                        }
                    }
                    return temp
                }
            } break;

            case '@': {
                if (d2) {

                    var temp = new Matrix(ri, sj)

                
                    for (var i = 0; i < ri; i++) {
                        for (var j = 0; j < sj; j++) {
                            for(var k=0; k<rj;k++)
                            //console.log(i,":",k,"::", k,":",j )
                            temp.m[i][j] += u.m[i][k] * v.m[k][j]


                        }
                    }

                    return temp
                }
            } break;


            case '/': {
                if (d6) {
                    var temp = new Matrix(ri, rj)
                    for (var i = 0; i < ri; i++) {
                        for (var j = 0; j < rj; j++) {

                            temp.m[i][j] = u.m[i][j] / v.m[i][j]

                            if (Number.isNaN(temp.m[i][j])) {
                                temp.m[i][j] = 0.0
                            }



                        }
                    }
                    return temp
                }
            } break;

            case '%': {
                if (d6) {
                    var temp = new Matrix(ri, rj)
                    for (var i = 0; i < ri; i++) {
                        for (var j = 0; j < rj; j++) {
                            temp.m[i][j] = u.m[i][j] % v.m[i][j]

                            if (Number.isNaN(temp.m[i][j])) {
                                temp.m[i][j] = 0.0
                            }

                        }
                    }
                    return temp
                }
            } break;
        }

    }


}

// var m = new Matrix(1000, 1)
// m.scan(6,{seq:true})
// //m.identity(1)
// m.transform()
// console.log(m.m)

// var a = new Matrix(1, 2000)
// a.scan(1, {})

// var b = new Matrix(2000, 1)
// b.scan(2.25, {})

// console.log(Matrix.mux(a,b))

export {Matrix};
