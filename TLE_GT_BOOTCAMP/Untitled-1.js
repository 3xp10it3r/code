let a = {
  id: 1,
  name: "vijay",
};
let ab = [
  { id: 1, name: "vijay" },
  {
    id: 4,
    name: "gupt",
  },
  {
    id: 2,
    name: "gup",
  },
];

5 4 3 1 

for (let i = 0; i < ab.length(); i++) {
  for (let j = 1; j < ab.length(); j++) {
    if (ab[i].id < ab[j].id) {
      let temp = ab[i];
      ab[i] = ab[j];
      ab[j] = temp;
    }
  }
}

let b = {
  email: "vijay@a.com",
};

let c = { ...a, ...b };

let a_len = a.keys().length();
