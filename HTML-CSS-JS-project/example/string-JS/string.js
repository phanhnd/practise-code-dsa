function reverse(str){
  return Array.from(str).reverse().join('');    
}
console.log(reverse('hello'));

function countOccurences(haystack, needle){
  if(needle === '') return 0; 
  const re = new RegExp(escapeRegExp(needle), 'gi');
  return [...haystack.matchAll(re)].length;
}
function escapeRegExp(s){
  return s.replace(/[.*+?^${}()|[\]\\]/g, '\\$&');
}

console.log("foo foofoo foo".replaceAll("foo", "bar"));

