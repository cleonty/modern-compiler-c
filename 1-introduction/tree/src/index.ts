import { insert, lookup, search, Tree } from "./tree"

let t: Tree | undefined;
t = insert('c', 'c', t);
t = insert('a', 'a', t);
t = insert('b', 'b', t);
t = insert('d', 'd', t);
t = insert('e', 'e', t);
console.log(JSON.stringify(t, null, 2));

console.assert(search('a', t));
console.assert(!search('x', t));

console.assert(lookup('a', t) === 'a');
console.assert(lookup('x', t) == undefined);