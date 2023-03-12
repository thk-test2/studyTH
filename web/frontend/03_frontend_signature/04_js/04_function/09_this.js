
// this
//// 일반 함수의 this는 호출 위치에서 정의
//// 화살표 함수의 this는 자신이 선언된 함수(렉시컬) 범위에서 정의

const user = {
    firstName: 'THK',
    lastName: 'Kyong',
    age: 84,
    getFullName: function() {
        return `${this.firstName} ${this.lastName}`;
    }
}

console.log(user.getFullName()); // this가 호출될 때 정의되므로, user에 해당.


const user2 = {
    firstName: 'THK',
    lastName: 'Kyong',
    age: 84,
    getFullName: () => {
        return `${this.firstName} ${this.lastName}`;
    }
}

console.log(user2.getFullName());

function user3() {
    this.firstName = 'Neo';
    this.lastName = 'Anderson';

    return {
        firstName: 'THK',
        lastName: 'Kyong',
        age: 84,
        // getFullName: () => {
        //     return `${this.firstName} ${this.lastName}`;
        // }
        getFullName() {
            return `${this.firstName} ${this.lastName}`;
        }
    }
}
const u = user3();
console.log(u.getFullName());

const lewis = {
    firstName: 'Lewis',
    lastName: 'Yang'
}
console.log(u.getFullName.call(lewis));



const timer = {
    title: 'TIMER!',
    timeout() {
        console.log(this.title);
        // setTimeout(function() {
        //     console.log(this.title);
        // }, 1000);
        setTimeout(()=> {
            console.log(this.title);
        }, 1000);
    }
}
timer.timeout();
