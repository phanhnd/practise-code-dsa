async function fetchAllData() {
  try {
    const [users, products, orders] = await Promise.all([
      User.find(),
      Product.find(),
      Order.find()
    ]);
  } catch (error) {
    console.error('Error fetching data: ', error);
    throw error; 
  }
}

