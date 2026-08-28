class TransferFunction {
    constructor({ n, f }) {
        this.n = n
        this.pick(f)
    }

    static HARDLIM = 'hardlim';
    static HARDLIMS = 'hardlims';
    static PURELIN = 'purelin';
    static SATLIN = 'satlin';
    static SATLINS = 'satlins';
    static LOGSIG = 'logsig';
    static TANSIG = 'tansig';
    static POSLIN = 'poslin';
    static COMPET = 'compet';



    pick(label) {
        switch (label) {
            case 'hardlim': this.hardlim(); break;
            case 'hardlims': return this.hardlims()
            case 'purelin': return this.purelin()
            case 'satlin': return this.satlin()
            case 'satlins': return this.satlins()
            case 'logsig': return this.logsig()
            case 'tansig': return this.tansig()
            case 'poslin': return this.poslin()
            case 'compet': return this.compet()
        }
    }


    hardlim() {

        for (var i = 0; i < this.n.row; i++) {
            for (var j = 0; j < this.n.column; j++) {
                this.n.m[i][j] = this.n.m[i][j] >= 0 ? 1 : 0
            }
        }

    }
    hardlims() {
        for (var i = 0; i < this.n.row; i++) {
            for (var j = 0; j < this.n.column; j++) {
                this.n.m[i][j] = this.n.m[i][j] >= 0 ? 1 : -1
            }
        }

    }
    purelin() {
        //this.n
    }
    satlin() {
        for (var i = 0; i < this.n.row; i++) {
            for (var j = 0; j < this.n.column; j++) {
                this.n.m[i][j] = ((this.n.m[i][j] >= 0) && (this.n.m[i][j] <= 1)) ? this.n.m[i][j] : (this.n.m[i][j] > 1) ? 1 : 0
            }
        }
    }

    satlins() {

        for (var i = 0; i < this.n.row; i++) {
            for (var j = 0; j < this.n.column; j++) {
                this.n.m[i][j] = ((this.n.m[i][j] >= -1) && (this.n.m[i][j] <= 1)) ? this.n.m[i][j] : (this.n.m[i][j] > 1) ? 1 : -1
            }
        }


        //return ((this.n >= -1) && (this.n <= 1)) ? this.n : (this.n > 1) ? 1 : -1 
    }
    logsig() {

        for (var i = 0; i < this.n.row; i++) {
            for (var j = 0; j < this.n.column; j++) {
                this.n.m[i][j] = 1.0 / (1 + Math.exp(-this.n.m[i][j]))
            }
        }

        // return 1.0 / (1 + Math.exp(- this.n.m[i][j])) 

    }
    tansig() {
        for (var i = 0; i < this.n.row; i++) {
            for (var j = 0; j < this.n.column; j++) {
                this.n.m[i][j] = Math.tanh(this.n.m[i][j])
            }
        }


        //return Math.tanh(this.n.m[i][j]) 

    }
    poslin() {

        for (var i = 0; i < this.n.row; i++) {
            for (var j = 0; j < this.n.column; j++) {
                this.n.m[i][j] = this.n.m[i][j] >= 0 ? this.n.m[i][j] : 0
            }
        }

        //return this.n.m[i][j] >= 0 ? this.n.m[i][j] : 0 

    }

    compet() {


        for (var i = 0; i < this.n.row; i++) {
            for (var j = 0; j < this.n.column; j++) {
                this.n.m[i][j] = 1.0
            }
        }


        //    return 1.0
    }


}

export { TransferFunction }