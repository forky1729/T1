#include <iostream>

namespace cat
{
    template<typename T>
    struct Node
    {
        T value;
        Node *next;
    };

    template<typename Iter, typename NodeType>
    struct InsertReturnType
    {
        Iter     position;
        bool     inserted;
        NodeType node;
    };

    template <typename Key, typename T, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>>
    class unordered_map
    {
        Key K;
        T value;

    public:
        //объявление имён ====================================================================
        using value_type = std::pair<const Key, T>;
        using size_type = std::size_t;
        using hasher = Hash;
        using key_equal = KeyEqual;
        using iterator = &value_type;                                                       //У
        using const_iterator = &const value_type;
        using local_iterator = iterator;
        using const_local_iterator = const_iterator;
        using node_type = Node;
        using insert_return_type = InsertReturnType;
        //(не используются в коде, но заявлены)
        //using key_type = Key;
        //using mapped_type = T;
        //using difference_type = std::ptrdiff_t;
        //using reference = value_type&;
        //using const_reference = const value_type&;
        //using pointer = ???;
        //using const_pointer = ???;

        //конструкторы =======================================================================
        ~unordered_map();                                                                   //А
        unordered_map();
        unordered_map( size_type bucket_count );
        unordered_map( size_type bucket_count,
                    const Hash& hash );
        template< typename InputIt >
        unordered_map( InputIt first, InputIt last,
                    size_type bucket_count,
                    const Hash& hash = Hash(),
                    const key_equal& equal = key_equal() );
        template< typename InputIt >
        unordered_map( InputIt first, InputIt last,
                    size_type bucket_count )
        template< typename InputIt >
        unordered_map( InputIt first, InputIt last,
                    size_type bucket_count,
                    const Hash& hash );
        unordered_map( const unordered_map& other );
        unordered_map( unordered_map&& other );

        //методы =============================================================================
        unordered_map& operator=( unordered_map&& other );                                  //А
        unordered_map& operator=( const unordered_map& other );

        //Iterators
        template <typename T>                                                               //Кс
        iterator begin();
        template <typename T>
        const_iterator begin() const;

        template <typename T>                                                               //Кс
        iterator end();
        template <typename T>
        const_iterator end() const;

        //Capacity
        bool empty() const;                                                                 //У

        std::size_type size() const;                                                        //Кт

        std::size_type max_size() const;                                                    //Кт

        //Modifiers
        void clear();                                                                       //А

        std::pair<iterator,bool> insert( const value_type& value );                         //У
        std::pair<iterator,bool> insert( value_type&& value );
        template< typename P >
        std::pair<iterator,bool> insert( P&& value );
        iterator insert( const_iterator hint, const value_type& value );
        iterator insert( const_iterator hint, value_type&& value );
        template< typename P >
        iterator insert( const_iterator hint, P&& value );
        template< typename InputIt >
        void insert( InputIt first, InputIt last );
        insert_return_type insert( node_type&& nh );
        iterator insert( const_iterator hint, node_type&& nh );

        template< typename M >                                                              //У
        std::pair<iterator, bool> insert_or_assign( const Key& k, M&& obj );
        template< typename M >
        std::pair<iterator, bool> insert_or_assign( Key&& k, M&& obj );
        template< typename M >
        iterator insert_or_assign( const_iterator hint, const Key& k, M&& obj );
        template< typename M >
        iterator insert_or_assign( const_iterator hint, Key&& k, M&& obj );

        template< typename... Args >                                                        //Кт
        std::pair<iterator,bool> emplace( Args&&... args );

        template <typename... Args>                                                         //Кт
        iterator emplace_hint( const_iterator hint, Args&&... args );

        template< typename... Args >                                                        //Кт
        std::pair<iterator, bool> try_emplace( const Key& k, Args&&... args );
        template< typename... Args >
        std::pair<iterator, bool> try_emplace( Key&& k, Args&&... args );
        template< typename... Args >
        iterator try_emplace( const_iterator hint, const Key& k, Args&&... args );
        template< typename... Args >
        iterator try_emplace( const_iterator hint, Key&& k, Args&&... args );
        
        iterator erase( iterator pos );                                                     //Кт
        iterator erase( const_iterator pos );
        iterator erase( const_iterator first, const_iterator last );
        size_type erase( const Key& key );
        template< typename K >
        size_type erase( K&& x );

        void swap( unordered_map& other );                                                  //Кс

        template<typename H2, typename P2>                                                  //А
        void merge( unordered_map<Key, T, H2, P2>& source );

        //Lookup
        T& at( const Key& key );                                                            //У
        const T& at( const Key& key ) const;

        T& operator[]( const Key& key );                                                    //У
        T& operator[]( Key&& key );

        size_type count( const Key& key ) const;                                            //А
        template< typename K >
        size_type count( const K& x ) const;

        iterator find( const Key& key );                                                    //У
        const_iterator find( const Key& key ) const;
        template< typename K >
        iterator find( const K& x );
        template< typename K >
        const_iterator find( const K& x ) const;

        bool contains( const Key& key ) const;                                              //У
        template< typename K >
        bool contains( const K& x ) const;

        //Bucket interface
        local_iterator begin( size_type n );                                                //Кс
        const_local_iterator begin( size_type n ) const;

        local_iterator end( size_type n );                                                  //Кс
        const_local_iterator end( size_type n ) const;

        size_type bucket_count() const;                                                     //Кт

        size_type max_bucket_count() const;                                                 //Кт

        size_type bucket_size( size_type n ) const;                                         //Кт

        size_type bucket( const Key& key ) const;                                           //Кт

        //Hash policy
        float load_factor() const;                                                          //Кс

        float max_load_factor() const;                                                      //Кс
        void max_load_factor( float ml );

        void rehash( size_type count );                                                     //А

        void reserve( size_type count );                                                    //А

        //Observers
        hasher hash_function() const;                                                       //Кс

        key_equal key_eq() const;                                                           //Кс

        //Non-member functions
        template <typename Key, typename T, typename Hash, typename KeyEqual>               //А
        void swap( unordered_map<Key, T, Hash, KeyEqual>& lhs,
                   unordered_map<Key, T, Hash, KeyEqual>& rhs );

        template <typename Key, typename T, typename Hash, typename KeyEqual, typename Pred>//У
        typename unordered_map<Key, T, Hash, KeyEqual>::size_type
            erase_if( unordered_map<Key, T, Hash, KeyEqual>& c, Pred pred );
    
    }; //class unordered_map
} //namespace cat

#include <unordered_map>

int main()
{
    std::cout << "function        " << "arguments        " << "std        " << "cat        " << std::endl;
    std::cout << "" << std:: << "" << cat:: << std::endl;
}
